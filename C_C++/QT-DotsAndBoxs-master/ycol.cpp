#include "ycol.h"

ycol::ycol(int y,int type)
{
    this->type=type;
    if(type==XYTYPE)
    this->y=y;
    if(type==COLTYPE)
    this->col=y;
}
int ycol::toCol()
{
    if(type==XYTYPE)
    return CHESS_FY+CHESS_LENGHT*(y-1);
    else
    return col;
}
int ycol::toY()
{
    if(type==COLTYPE)
    return (col-CHESS_FY)/CHESS_LENGHT+1;
    else
        return y;
}
