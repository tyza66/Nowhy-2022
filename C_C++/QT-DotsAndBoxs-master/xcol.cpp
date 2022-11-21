#include "xcol.h"

Xcol::Xcol(int x,int type)
{
    this->type=type;
    if(type==XYTYPE)
    this->x=x;
    if(type==COLTYPE)
    this->col=x;
}
int Xcol::toCol()
{
    if(type==XYTYPE)
    return CHESS_FX+CHESS_LENGHT*(x-1);
    else
    return col;
}
int Xcol::toX()
{
    if(type==COLTYPE)
    return (col-CHESS_FX)/CHESS_LENGHT+1;
    else
    return x;
}
