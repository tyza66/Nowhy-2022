#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"
unsigned char KeyNum;
void main(){
	LCD_Init();
	while(1){
		KeyNum = MatrixKey();
		if(KeyNum){
			LCD_ShowNum(2,1,KeyNum,2);
		}
	}
	
}