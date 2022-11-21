#ifndef MINMAXAI_H
#define MINMAXAI_H
#include <chessborad.h>
#include <gogal.h>
class MinMaxAi
{
public:
    MinMaxAi(chessBorad * borad);
    chessBorad aiBorad;
    int boxOfSide[(CHESS_X_NUM-1)*(CHESS_Y_NUM-1)][4];
    int valBorad[(CHESS_X_NUM-1)*CHESS_Y_NUM+(CHESS_Y_NUM-1)*CHESS_X_NUM+1];
    int MinMax(int alpha,int beta,int depth);
    int getScore();
    int AiMove();
    int getMakeFore();
    int getMax(int alpha,int beta,int depth);
    int getMin(int alpha,int beta,int depth);
private:
    bool isEnd();
    int moveRecord=0;
};

#endif // MINMAXAI_H
