#include <REGX52.H>
#include <INTRINS.H>
void Delay500ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


main(){
	while(1){
		P2 = 0xFE;
		Delay500ms();
		P2 = 0xFD;
		Delay500ms();
		P2 = 0xFB;
		Delay500ms();
		P2 = 0xF7;
		Delay500ms();
		P2 = 0xEF;
		Delay500ms();
		P2 = 0xDF;
		Delay500ms();
		P2 = 0xBF;
		Delay500ms();
		P2 = 0x7F;
		Delay500ms();
	}
}
