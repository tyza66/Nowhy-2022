#ifndef Final_Occupy_h_
#define Final_Occupy_h_





#include "Dots and Boxes.h"
#include "Evaluate.h"
//#include "Move.h"
//#include "Search.h"

void Put_chessboard(int etype,int i, int j);
int Give_Boxes_Odd ();
int Chain_lenth(int x,int y);
int  Eat_Chain(int i,int j,int len);
void None_Antdoublecorse()	;
void Eat_all_box()	;
void Odd_Number_Doublecorse();
void Oven_Number_Doublecorse();
void Min_Give_Box();
void put();
void Eat_a_chain(int i,int j,int len);
extern void Final_Occupy();
int Count_AntDoublecorse(); 
#endif