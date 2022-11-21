#include "minmaxai.h"

MinMaxAi::MinMaxAi(chessBorad * borad)
{
    aiBorad.copyDate(borad);
    for(int i=1;i<=CHESS_ALL_SIDE_NUM;i++)
    {

        valBorad[i]=0;
    }
    moveRecord=0;
}

int MinMaxAi::AiMove()
{
    int putIndex=-1;
    int val=-99999;
    for(int i=0;i<CHESS_ALL_SIDE_NUM;i++)
    {
        if(!aiBorad.getRole(i))
        {
            aiBorad.downHere(i);
            int temp=-MinMax(-9999,9999,3);
            printf("%d:%d ",i,temp);
            if(val<temp&&temp>=-20)
            {
                val=temp;
                putIndex=i;
            }
            aiBorad.backBorad();
        }
    }
    printf("\nred:%d,blue:%d\n",aiBorad.getRedCount(),aiBorad.getBlueCount());
    printf("\nbestVal=%d,putIndex:%d,Move:%d\n",val,putIndex,moveRecord);
    fflush(stdout);
    return putIndex;
}
int MinMaxAi::MinMax(int alpha,int beta,int depth)
{

    if(!depth||aiBorad.isEnd())
    {
        moveRecord++;
        return getScore();
    }
    int forIndex=getMakeFore();
    int best=-9999;
    int tempAlpha=alpha;
    if(forIndex)
    {
        aiBorad.downHere(forIndex);
        int val=MinMax(alpha,beta,depth);
        aiBorad.backBorad();
        return val;
    }
    else
    {
        for(int i=0;i<CHESS_ALL_SIDE_NUM;i++)
        {
           if(!aiBorad.getRole(i))
                {
                    aiBorad.downHere(i);
                    int value=-MinMax(-beta,-tempAlpha,depth-1);
                    aiBorad.backBorad();
                    if(value>best)
                        best=value;
//                    if(best>alpha)
//                        tempAlpha=best;
//                    if(best>=beta)
//                        break;
                }
        }
        return best;
    }
}
int MinMaxAi::getMin(int alpha, int beta, int depth)
{

}
int MinMaxAi::getMax(int alpha, int beta, int depth)
{

}
int MinMaxAi::getScore()
{
      return aiBorad.getRedCount()-aiBorad.getBlueCount();
}
int MinMaxAi::getMakeFore()
{
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        int count=0;
        int forIndex=0;
        for(int j=0;j<4;j++)
        {
            if(aiBorad.getRole(aiBorad.boxOfSide[i][j]))
            {
                count++;
            }
            else
            {
                forIndex=aiBorad.boxOfSide[i][j];
            }
        }
        if(count==3)
        {
            return forIndex;
        }
    }
    return 0;
}
bool MinMaxAi::isEnd()
{
    bool isEnd=true;
    for(int i=0;i<CHESS_ALL_SIDE_NUM;i++)
    {
        if(!aiBorad.getRole(i))
        {
            isEnd=false;
        }
    }
    return isEnd;
}
