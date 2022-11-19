#include "iic_oled.h"
#include "font.h"
/**********************************************
//IIC Start
**********************************************/
void IIC_Start()
{
	OLED_SCL = 1;
	OLED_SDIN = 1;
	OLED_SDIN = 0;
	OLED_SCL = 0;
}

/**********************************************
//IIC Stop
**********************************************/
void IIC_Stop()
{
	OLED_SCL = 1 ;
	OLED_SDIN = 0;
	OLED_SDIN = 1;

}

void IIC_Wait_Ack()
{
	OLED_SCL = 1 ;
	OLED_SCL = 0;
}
/**********************************************
// IIC Write byte
**********************************************/
void Write_IIC_Byte(u8 IIC_Byte)
{
	u8 i;
	u8 m, da;
	da = IIC_Byte;
	OLED_SCL = 0;
	for(i = 0; i < 8; i++)
	{
		m = da;
		m = m & 0x80;
		if(m == 0x80)
		{
			OLED_SDIN = 1;
		}
		else OLED_SDIN = 0;
		da = da << 1;
		OLED_SCL = 1;
		OLED_SCL = 0;
	}


}
/**********************************************
// IIC Write Command
**********************************************/
void Write_IIC_Command(u8 IIC_Command)
{
	IIC_Start();
	Write_IIC_Byte(0x78);            //Slave address,SA0=0
	IIC_Wait_Ack();
	Write_IIC_Byte(0x00);			//write command
	IIC_Wait_Ack();
	Write_IIC_Byte(IIC_Command);
	IIC_Wait_Ack();
	IIC_Stop();
}
/**********************************************
// IIC Write Data
**********************************************/
void Write_IIC_Data(u8 IIC_Data)
{
	IIC_Start();
	Write_IIC_Byte(0x78);			//D/C#=0; R/W#=0
	IIC_Wait_Ack();
	Write_IIC_Byte(0x40);			//write data
	IIC_Wait_Ack();
	Write_IIC_Byte(IIC_Data);
	IIC_Wait_Ack();
	IIC_Stop();
}
void OLED_WR_Byte(unsigned dat, unsigned cmd)
{
	if(cmd)
		Write_IIC_Data(dat);
	else
		Write_IIC_Command(dat);
}

//坐标设置
void OLED_Set_Pos(u8 x, u8 y)
{
	OLED_WR_Byte(0xb0 + y, 0);
	OLED_WR_Byte((((x + 2) & 0xf0) >> 4) | 0x10, 0);
	OLED_WR_Byte(((x + 2) & 0x0f), 0);
}

void OLED_Clear(void)
{
	u8 m, n;
	for(m = 0; m < 8; m++)
	{
		OLED_WR_Byte(0xb0 + m, 0);		//page0-page1
		OLED_WR_Byte(0x00, 0);		//low column start address
		OLED_WR_Byte(0x10, 0);		//high column start address
		for(n = 0; n < 128; n++)
		{
			OLED_WR_Byte(0x00, 1);
		}
	}
}

//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
void OLED_ShowChar(u8 x, u8 y, u8 chr)
{
	u8 c = 0, i = 0;
	c = chr - ' '; //得到偏移后的值
	if(x > Max_Column - 1)
	{
		x = 0;
		y = y + 2;
	}
	OLED_Set_Pos(x, y);
	for(i = 0; i < 8; i++)
		OLED_WR_Byte(zf[c * 16 + i], 1);
	OLED_Set_Pos(x, y + 1);
	for(i = 0; i < 8; i++)
		OLED_WR_Byte(zf[c * 16 + i + 8], 1);

}
//m^n函数
u32 oled_pow(u8 m, u8 n)
{
	u32 result = 1;
	while(n--)result *= m;
	return result;
}
//显示数字
//x,y :起点坐标
//len :数字的位数
//num:数值(0~4294967295)
//mode:显示格式：为0，当要显示的最高位为0时显示时，显示空格，为1，当要显示的最高位为0时显示时，显示0
void OLED_ShowNum(u8 x, u8 y, u32 num, u8 len, u8 mode)
{
	u8 t, temp;
	u8 enshow = 0;
	for(t = 0; t < len; t++)
	{
		temp = (num / oled_pow(10, len - t - 1)) % 10;
		if(enshow == 0 && t < (len - 1))
		{
			if(temp == 0)
			{
				if(mode == 0)
					OLED_ShowChar(x + 8 * t, y, ' ');
				else
					OLED_ShowChar(x + 8 * t, y, '0');
				continue;
			}
			else enshow = 1;
		}
		OLED_ShowChar(x + 8 * t, y, temp + '0');
	}
}

//初始化SSD1306
void OLED_Init(void)
{
	OLED_WR_Byte(0xAE, 0); //--display off
	OLED_WR_Byte(0x00, 0); //---set low column address
	OLED_WR_Byte(0x10, 0); //---set high column address
	OLED_WR_Byte(0x40, 0); //--set start line address
	OLED_WR_Byte(0xB0, 0); //--set page address
	OLED_WR_Byte(0x81, 0); // contract control
	OLED_WR_Byte(0xFF, 0); //--128
	OLED_WR_Byte(0xA1, 0); //set segment remap
	OLED_WR_Byte(0xA6, 0); //--normal / reverse
	OLED_WR_Byte(0xA8, 0); //--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3F, 0); //--1/32 duty
	OLED_WR_Byte(0xC8, 0); //Com scan direction
	OLED_WR_Byte(0xD3, 0); //-set display offset
	OLED_WR_Byte(0x00, 0); //

	OLED_WR_Byte(0xD5, 0); //set osc division
	OLED_WR_Byte(0x80, 0); //

	OLED_WR_Byte(0xD8, 0); //set area color mode off
	OLED_WR_Byte(0x05, 0); //

	OLED_WR_Byte(0xD9, 0); //Set Pre-Charge Period
	OLED_WR_Byte(0xF1, 0); //

	OLED_WR_Byte(0xDA, 0); //set com pin configuartion
	OLED_WR_Byte(0x12, 0); //

	OLED_WR_Byte(0xDB, 0); //set Vcomh
	OLED_WR_Byte(0x30, 0); //

	OLED_WR_Byte(0x8D, 0); //set charge pump enable
	OLED_WR_Byte(0x14, 0); //

	OLED_WR_Byte(0xAF, 0); //--turn on oled panel
}

