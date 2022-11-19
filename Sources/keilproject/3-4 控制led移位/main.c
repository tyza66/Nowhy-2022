#include <REGX52.H>
void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}
unsigned char LEDNum;
void main(){
	P2 = 0Xfe;
	while(1){
		if(P3_0==0){
			Delay(20);
			while(P3_0==0);
			Delay(20);
			LEDNum++;
			if(LEDNum>=8){
				LEDNum = 0;
			}
			P2 = ~(0X01<<LEDNum);
		}
		if(P3_1==0){
			Delay(20);
			while(P3_1==0);
			Delay(20);
			LEDNum--;
			if(LEDNum==0){
				LEDNum = 7;
			}
			P2 = ~(0X01<<LEDNum);
		}
	}
}
