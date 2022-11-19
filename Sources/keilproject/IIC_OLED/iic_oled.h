#ifndef __OLED_H
#define __OLED_H	
#include "reg51.h"
#include "iic_oled.h"
#define u8 unsigned char 
#define u16 unsigned int
#define u32 unsigned long  	  

#define Max_Column	128
#define Max_Row		64 

//-----------------OLED端口定义----------------  
sbit OLED_SCL=P2^1;//SCL
sbit OLED_SDIN=P2^0;//SDA

//OLED控制用函数
void OLED_WR_Byte(unsigned dat,unsigned cmd);    							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_Fill(u8 fill_Data);
void OLED_ShowChar(u8 x,u8 y,u8 chr);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 mode);	 
void OLED_Set_Pos(u8 x, u8 y);
#endif  