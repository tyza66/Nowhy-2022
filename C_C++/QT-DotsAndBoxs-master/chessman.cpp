#include "chessman.h"


Xcol ChessMan::getFristX()
{

    if(index<=CHESS_HOR_NUM)
    {
        int temp=(index-1)%(CHESS_X_NUM-1)+1;
        Xcol x1(temp,XYTYPE);
        return x1;
    }
    else
    {
        int temp=index-CHESS_HOR_NUM;
        temp=(temp-1)/(CHESS_Y_NUM-1)+1;
        Xcol x1(temp,XYTYPE);
        return x1;
    }
}
ycol ChessMan::getFristY()
{
    if(index<=CHESS_HOR_NUM)
    {
        int temp=(index-1)/(CHESS_X_NUM-1)+1;
        ycol y1(temp,XYTYPE);
        return y1;
    }
    else
    {
        int temp=(index-CHESS_HOR_NUM-1)%(CHESS_Y_NUM-1)+1;
        ycol y1(temp,XYTYPE);
        return y1;
    }
}
Xcol ChessMan::getSecondX()
{
    if(index<=CHESS_HOR_NUM)
    {
        int temp=(index-1)%(CHESS_X_NUM-1)+2;
        Xcol x1(temp,XYTYPE);
        return x1;
    }
    else
    {
        int temp=index-CHESS_HOR_NUM;
        temp=(temp-1)/(CHESS_Y_NUM-1)+1;
        Xcol x1(temp,XYTYPE);
        return x1;
    }
}
ycol ChessMan::getSecondY()
{
    if(index<=CHESS_HOR_NUM)
    {
        int temp=(index-1)/(CHESS_X_NUM-1)+1;
        ycol y1(temp,XYTYPE);
        return y1;
    }
    else
    {
        int temp=(index-CHESS_HOR_NUM-1)%(CHESS_Y_NUM-1)+1;
        temp=temp+1;
        ycol y1(temp,XYTYPE);
        return y1;
    }
}
ChessMan::ChessMan(Xcol x1,ycol y1,Xcol x2,ycol y2)
{
    if(y1.toY()==y2.toY())
    {
        index=(y1.toY()-1)*(CHESS_Y_NUM-1)+x1.toX();
    }
    if(x1.toX()==x2.toX())
    {
        index=CHESS_HOR_NUM+(x1.toX()-1)*(CHESS_X_NUM-1)+y1.toY();
    }
}
ChessMan::ChessMan(int index)
{
    this->index=index;
}
ChessMan::ChessMan(Xcol x,ycol y)
{
    index=0;
    for(int i=1;i<=CHESS_ALL_SIDE_NUM;i++)
    {
        ChessMan Temp(i);
        if(i<=CHESS_HOR_NUM)
        {
            if(x.toCol()>=Temp.getFristX().toCol()+10&&x.toCol()<=Temp.getSecondX().toCol()-5)
            {

                if(y.toCol()<=Temp.getFristY().toCol()+15&&y.toCol()>=Temp.getFristY().toCol()-5)
                {
                    this->index=i;
                    break;
                }
            }
        }
        else
        {
            if(y.toCol()>=Temp.getFristY().toCol()+10&&y.toCol()<=Temp.getSecondY().toCol()-5)
            {
                if(x.toCol()<=Temp.getFristX().toCol()+15&&x.toCol()>=Temp.getFristX().toCol()-5)
                {
                    this->index=i;
                    break;
                }
            }
        }
    }

}
int ChessMan::getIndex()
{
    return index;
}
