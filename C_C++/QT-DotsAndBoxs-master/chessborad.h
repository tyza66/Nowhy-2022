#ifndef CHESSBORAD_H
#define CHESSBORAD_H
#include <caculate.h>
#include <chessman.h>
#include <gogal.h>
#include <QMessageBox>
#include <QStack>
class chessBorad
{
private:
    QStack<int> recordBorad;
    QStack<int> recordColor;
    QStack<QString> AiRecordBorad;
public:
    int borad[(CHESS_X_NUM-1)*CHESS_Y_NUM+(CHESS_Y_NUM-1)*CHESS_X_NUM+1];
    int box[(CHESS_X_NUM-1)*(CHESS_Y_NUM-1)];
    int recordRedBox[(CHESS_X_NUM-1)*(CHESS_Y_NUM-1)];
    int recordBlueBox[(CHESS_X_NUM-1)*(CHESS_Y_NUM-1)];
    int redBoxMark;
    int blueBoxMark;
    int boxOfSide[(CHESS_X_NUM-1)*(CHESS_Y_NUM-1)][4];
    int color=1;
    chessBorad();
    int getColor();
    int changeColor();
    void inition();
    int getFristLine(int box);
    int getSecondLine(int box);
    bool checkBoxs(int index);
    bool checkBoxs(int index,int fillColor);
    bool downHere(int index);
    void setBorad(int index,int role);
    int getRole(int index);
    int getBoxRole(int box);
    bool isEnd();
    int whoWin();
    int getRedCount();
    int getBlueCount();
    int backBorad();
    int getRedBoxMark(int box);
    int getBlueBoxMark(int box);
    void refreshBoxs();
    int * getBorad();
    void copyDate(chessBorad * temp);
};

#endif // CHESSBORAD_H
