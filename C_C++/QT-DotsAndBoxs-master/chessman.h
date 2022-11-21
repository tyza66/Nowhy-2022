#ifndef CHESSMAN_H
#define CHESSMAN_H
#include <gogal.h>
#include <xcol.h>
#include <ycol.h>
class ChessMan
{
private:
    int index;

public:
    ChessMan(int index);
    ChessMan(Xcol x1,ycol y1,Xcol x2,ycol y2);
    ChessMan(Xcol x,ycol y);
    Xcol getFristX();
    ycol getFristY();
    Xcol getSecondX();
    ycol getSecondY();
    int getIndex();
};

#endif // CHESSMAN_H
