#ifndef GREEDAI_H
#define GREEDAI_H
#include <gogal.h>
#include <QStack>
#include <minmaxai.h>
#include <qglobal.h>
#include <QTime>
#include <QThread>
#include <QApplication>
class greedAi
{
private:
    int boxOfSide[(CHESS_X_NUM-1)*(CHESS_Y_NUM-1)][4];//格子对应的边
    int singleLine[(CHESS_X_NUM-1)*2+2*(CHESS_Y_NUM-1)];//一对一的边
    int boradScord[(CHESS_X_NUM-1)*CHESS_Y_NUM+(CHESS_Y_NUM-1)*CHESS_X_NUM+1];//格子分数
    int borad[(CHESS_X_NUM-1)*CHESS_Y_NUM+(CHESS_Y_NUM-1)*CHESS_X_NUM+1];//格子边数组
    int bookBox[(CHESS_X_NUM-1)*(CHESS_Y_NUM-1)];//记录格子是否已经被残局标记
    int MAKE_FORE=9999;
    int ZERO=500;
    int ONE=100;
    int TWO=-2000;
    bool isHaveDown=false;
    chessBorad * b1;
public:
    greedAi();
    int aiMove();
    int searchEnding();
    //int searchThreeBoxLine(int box);
    int deepSearchEnding(int index,int box);//衍生搜索;
    int produceGiveAwayDown(int index);//产生让格走法
    void setBorad(chessBorad borad);
    int aiSearch(int index);
    int getScore(int num);
    void setAiDown(bool is);
    int getScore(int num1,int num2);
    int getBoxHave(int box);
    int searchThisBoxList(int index);
    int searchSmallBoxList(int index);
    bool isFinalTurn();//判断是否处于残局
    bool isEndTurn();//判断是否仅剩下最后一条长链
    void sleep(unsigned int msec);
    void printScore();
};

#endif // GREEDAI_H
