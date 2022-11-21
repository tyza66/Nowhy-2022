#include "chessborad.h"

chessBorad::chessBorad()
{
    inition();

}
void chessBorad::inition()
{
    for(int i=1;i<=CHESS_ALL_SIDE_NUM;i++)
    {
        borad[0]=-1;
        borad[i]=0;
    }
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        box[i]=0;
        recordBlueBox[i]=0;
        recordRedBox[i]=0;
    }
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        int el1=i%(CHESS_X_NUM-1);
        int el2=i/(CHESS_X_NUM-1);
        boxOfSide[i][0]=i+1;
        boxOfSide[i][1]=i+CHESS_X_NUM;
        boxOfSide[i][2]=CHESS_HOR_NUM+1+el1*(CHESS_Y_NUM-1)+el2;
        boxOfSide[i][3]=boxOfSide[i][2]+(CHESS_Y_NUM-1);
    }
    color=1;
    recordBorad.clear();
    recordColor.clear();
    AiRecordBorad.clear();
    redBoxMark=0;
    blueBoxMark=0;
}
bool chessBorad::downHere(int index)
{

    if(!borad[index])
    {
        bool isChange=checkBoxs(index,getColor());
        borad[index]=color;
        if(GAMEMOD==PVP)
        {
            recordBorad.push(index);
            recordColor.push(color);
        }
        if(GAMEMOD==PVE)
        {
            if(!AiRecordBorad.isEmpty())
            {
                QString infor=AiRecordBorad.top();
                QString color=infor.split("|")[0];
                if(color.toInt()==getColor())
                {
                    infor+=","+QString::number(index);
                    AiRecordBorad.pop();
                }
                else
                {
                    infor=QString::number(getColor())+"|"+QString::number(index);
                }
                AiRecordBorad.push(infor);
            }
            else
            {
                AiRecordBorad.push(QString::number(getColor())+"|"+QString::number(index));
            }
        }
        if(!isChange)
        {
            changeColor();
            return true;//改变颜色返回真
        }
        return false;
    }

}
int chessBorad::getColor()
{
    return color;
}
int chessBorad::changeColor()
{
    color=!(color-1)+1;
    return color;
}
int chessBorad::getRole(int index)
{
    return borad[index];
}
bool chessBorad::checkBoxs(int index)
{
    bool isFill=false;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(boxOfSide[i][j]==index)
            {
                int count=0;
                for(int k=0;k<4;k++)
                {
                    if(borad[boxOfSide[i][k]])
                    {count++;}
                }
                if(count>=3)
                {
                    isFill=true;
                }
            }
        }
    }
    return isFill;
}
bool chessBorad::checkBoxs(int index,int fillColor)
{
    bool isFill=false;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(boxOfSide[i][j]==index)
            {
                int count=0;
                for(int k=0;k<4;k++)
                {
                    if(boxOfSide[i][k]==index)
                        continue;
                    if(borad[boxOfSide[i][k]])
                    {count++;}
                }
                if(count>=3)
                {
                    isFill=true;
                    box[i]=fillColor;
                    if(fillColor==1)
                    {
                        redBoxMark++;
                        recordRedBox[i]=redBoxMark;
                    }
                    if(fillColor==2)
                    {
                        blueBoxMark++;
                        recordBlueBox[i]=blueBoxMark;
                    }
                }
            }
        }
    }
    return isFill;
}
int chessBorad::getFristLine(int box)
{
    return boxOfSide[box][0];
}
int chessBorad::getSecondLine(int box)
{
    return boxOfSide[box][1];
}
int chessBorad::getBoxRole(int box)
{
    return this->box[box];
}
bool chessBorad::isEnd()
{
    bool isFillWithTheBox=true;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        if(!box[i])
            isFillWithTheBox=false;
    }
    return isFillWithTheBox;
}
int chessBorad::whoWin()
{
    int red=getRedCount();
    int blue=getBlueCount();
    if(red==blue)
        return 0;
    if(red>blue)
        return 1;
    if(blue>red)
        return 2;
}
int chessBorad::getRedCount()
{
    int temp=0;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        if(box[i]==1)
            temp++;
    }
    return temp;
}
int chessBorad::getBlueCount()
{
    int temp=0;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        if(box[i]==2)
            temp++;
    }
    return temp;
}
void chessBorad::setBorad(int index, int role)
{
    borad[index]=role;
}
int chessBorad::backBorad()
{
    if(GAMEMOD==PVP)
    {
        if(!recordBorad.isEmpty()&&!recordColor.isEmpty())
        {
            borad[recordBorad.top()]=0;
            color=recordColor.top();
            recordColor.pop();
            recordBorad.pop();
            refreshBoxs();
        }
    }
    else if(GAMEMOD==PVE)
    {
        if(!AiRecordBorad.isEmpty())
        {
            QString infor=AiRecordBorad.top();
            QString downColorString=infor.split("|")[0];
            int downColor=downColorString.toInt();
            QString downData=infor.split("|")[1];
            QStringList AiList=downData.split(",");
            for(int i=0;i<AiList.length();i++)
            {
                QString thisIndex=AiList[i];
                borad[thisIndex.toInt()]=0;
            }
            if(downColor!=AIDOWNCOLOR)
            {changeColor();}
            AiRecordBorad.pop();
            refreshBoxs();
            if(!AiRecordBorad.isEmpty()&&downColor==AIDOWNCOLOR)
            {
                QString infor=AiRecordBorad.top();
                QString color=infor.split("|")[0];
                QString downData=infor.split("|")[1];
                QStringList AiList=downData.split(",");
                for(int i=0;i<AiList.length();i++)
                {
                    QString thisIndex=AiList[i];
                    borad[thisIndex.toInt()]=0;
                }
                if(downColor!=AIDOWNCOLOR)
                {
                    changeColor();
                }
                AiRecordBorad.pop();
                refreshBoxs();
            }
            else
            {
                changeColor();
            }
        }
    }
}
void chessBorad::refreshBoxs()
{
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        int Count=0;
        for(int j=0;j<4;j++)
        {

            if(borad[boxOfSide[i][j]])
            {
                Count++;
            }
        }
        if(Count!=4)
        {
            if(box[i]==1)
            {
                recordRedBox[i]=0;
                redBoxMark--;
            }
            if(box[i]==2)
            {
                recordBlueBox[i]=0;
                blueBoxMark--;
            }
            box[i]=0;

        }
    }
}
int chessBorad::getBlueBoxMark(int box)
{
    return recordBlueBox[box];
}
int chessBorad::getRedBoxMark(int box)
{
    return recordRedBox[box];
}
int *chessBorad::getBorad()
{
    return borad;
}
void chessBorad::copyDate(chessBorad *temp)
{
    for(int i=0;i<CHESS_ALL_SIDE_NUM;i++)
    {
        this->borad[i]=temp->borad[i];
    }
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        this->box[i]=temp->box[i];
        this->recordRedBox[i]=temp->recordRedBox[i];
        this->recordBlueBox[i]=temp->recordBlueBox[i];
        for(int j=0;j<4;j++)
            this->boxOfSide[i][j]=temp->boxOfSide[i][j];
    }
}
