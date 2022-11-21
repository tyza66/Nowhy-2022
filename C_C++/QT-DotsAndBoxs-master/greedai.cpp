#include "greedai.h"
greedAi::greedAi()
{
    for(int i=0;i<CHESS_BOX_NUM;i++)//初始化box的边
    {
        int el1=i%(CHESS_X_NUM-1);
        int el2=i/(CHESS_X_NUM-1);
        boxOfSide[i][0]=i+1;
        boxOfSide[i][1]=i+CHESS_X_NUM;
        boxOfSide[i][2]=CHESS_HOR_NUM+1+el1*(CHESS_Y_NUM-1)+el2;
        boxOfSide[i][3]=boxOfSide[i][2]+(CHESS_Y_NUM-1);
    }
    for(int i=0;i<CHESS_X_NUM-1;i++)//初始化box的单边
    {
       singleLine[i]=boxOfSide[i][0];
       singleLine[i+CHESS_X_NUM-1]=boxOfSide[i+(CHESS_X_NUM-1)*(CHESS_Y_NUM-2)][1];
    }
    for(int i=0;i<CHESS_Y_NUM-1;i++)//初始化box的单边
    {
        singleLine[i+(CHESS_X_NUM-1)*2]=boxOfSide[0][2]+i;
        singleLine[i+(CHESS_X_NUM-1)*2+(CHESS_Y_NUM-1)]=boxOfSide[CHESS_X_NUM-2][3]+i;
    }
    memset(boradScord,0,sizeof(int));
}
int greedAi::aiMove()
{
    int bigScore=-9999;
    QStack <int> bestSelet;
    for(int i=1;i<=CHESS_ALL_SIDE_NUM;i++)
    {
        if(!borad[i])
        {
            int thisScore=aiSearch(i);
            if(thisScore>bigScore)
            {
                bestSelet.clear();
                bigScore=thisScore;
                bestSelet.push(i);
            }
            else if(thisScore==bigScore)
            {
                bestSelet.push(i);
            }
        }
    }
    if(bigScore<0)
    {
//        MinMaxAi temp(this->b1);
//        return temp.AiMove();
        return searchEnding();
    }
    else if(bigScore>5000)
    {
        //qDebug()<<isFinalTurn()<<"-"<<isHaveDown;
        if(isFinalTurn()&&!isEndTurn())//让格走法
        {
            int downLine=bestSelet.top();
            if(searchSmallBoxList(downLine)>(searchThisBoxList(downLine))&&searchThisBoxList(downLine)<=2&&isHaveDown)
            {
                isHaveDown=false;
                return produceGiveAwayDown(downLine);
            }
            if(searchThisBoxList(downLine)>=4)
            {
                isHaveDown=true;
            }
        }
    }
    //qDebug()<<"最大分数"<<bigScore;
    int tempSelet[(CHESS_X_NUM-1)*CHESS_Y_NUM+(CHESS_Y_NUM-1)*CHESS_X_NUM];
    int count=0;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    while(!bestSelet.isEmpty())
    {
        tempSelet[count]=bestSelet.top();
        count++;
        bestSelet.pop();
    }
    int tempIndex;
    while(true)
    {
        tempIndex=qrand()%count;
        if(tempSelet[tempIndex]<CHESS_ALL_SIDE_NUM||tempSelet[tempIndex]>0)
            break;
    }
    return tempSelet[tempIndex];
}
void greedAi::setBorad(chessBorad borad)
{
    this->b1=&borad;
    for(int i=0;i<=CHESS_ALL_SIDE_NUM;i++)//初始化Borad
    {
        this->borad[i]=b1->getRole(i);
    }

}
int greedAi::aiSearch(int index)
{
    int count=0;
    int fristBox=0;
    int secondBox=0;
    bool isSingleLine=false;
    bool out=false;
    for(int i=0;i<CHESS_ALL_SIDE_NUM;i++)
        if(singleLine[i]==index)
            isSingleLine=true;
    for(int i=0;i<CHESS_ALL_SIDE_NUM;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(boxOfSide[i][j]==index)
            {
                count++;
                if(count==1)
                {
                   fristBox=i;
                   if(isSingleLine)
                       out=true;
                }
                if(count==2)
                {
                   secondBox=i;
                   out=true;
                   break;
                }
            }
        }
        if(out)
        {
            break;
        }
    }
    if(isSingleLine)
    {
        return getScore(getBoxHave(fristBox));
    }
    else
    {
        return getScore(getBoxHave(fristBox),getBoxHave(secondBox));
    }
}
int greedAi::getScore(int num)
{
    if(num==0)
        return ZERO;
    if(num==1)
        return ONE;
    if(num==2)
        return TWO;
    if(num==3)
        return MAKE_FORE;
}
int greedAi::getScore(int num1, int num2)
{
    return getScore(num1)+getScore(num2);
}
int greedAi::getBoxHave(int box)
{
    int count=0;
    for(int j=0;j<4;j++)
    {
       if(borad[boxOfSide[box][j]])
             count++;
    }
    return count;
}
int greedAi::searchEnding()
{
    int MinBoxList=9999;
    int MinBoxLine=-1;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {bookBox[i]=b1->getBoxRole(i);}//格局复制
    for(int i=0;i<CHESS_BOX_NUM;i++)//搜索三边问题
    {
        if(getBoxHave(i)==1&&!bookBox[i])
        {
            for(int j=0;j<4;j++)
            {
                if(!b1->getRole(boxOfSide[i][j]))
                {
                    bookBox[i]=1;
                    int thisVule=deepSearchEnding(boxOfSide[i][j],i)+1;
                    bookBox[i]=0;
                    if(MinBoxList>thisVule&&thisVule>0)
                    {
                        MinBoxList=thisVule;
                        MinBoxLine=boxOfSide[i][j];
                    }
                }
            }
        }
    }
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {bookBox[i]=b1->getBoxRole(i);}//格局复制
    for(int i=0;i<CHESS_BOX_NUM;i++)//搜索长链
    {
        if(!bookBox[i])
        {
            int checkBoxNum=1;
            int findLine;
            for(int j=0;j<4;j++)
            {
                findLine=boxOfSide[i][j];
                if(!b1->getRole(findLine))
                {
                    checkBoxNum+=deepSearchEnding(findLine,i);
                }
            }
            qDebug()<<checkBoxNum;
            if(MinBoxList>checkBoxNum&&checkBoxNum>0)
            {
                MinBoxList=checkBoxNum;
                for(int j=0;j<4;j++)
                {
                    if(!b1->getRole(boxOfSide[i][j]))
                        MinBoxLine=boxOfSide[i][j];
                }
            }
        }
    }
    qDebug()<<"bestLine:"<<MinBoxLine<<"bestBox:"<<MinBoxList;
    qDebug()<<"_________________";
    return MinBoxLine;
}
int greedAi::deepSearchEnding(int index, int box)
{
    int isFind=false;
    int nextLine;
    int thisBox;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        for(int j=0;j<4;j++)
        {
           if(boxOfSide[i][j]==index&&i!=box&&!bookBox[i])
           {
               isFind=true;
               for(int k=0;k<4;k++)
               {
                   int findLine=boxOfSide[i][k];
                   if(b1->getRole(findLine)==0&&findLine!=index)
                   {
                       thisBox=i;
                       nextLine=findLine;
                   }
               }
               bookBox[i]=1;
           }
        }
    }
    if(isFind)
    {
        return deepSearchEnding(nextLine,thisBox)+1;
    }
    else
    {
        return 0;
    }

}
void greedAi::sleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}
bool greedAi::isFinalTurn()
{
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        if(getBoxHave(i)<2)
        {return false;}
    }
    return true;
}
void greedAi::setAiDown(bool is)
{
    isHaveDown=is;
}
int greedAi::produceGiveAwayDown(int index)
{
    int ThreeBox;
    int NextBox;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {bookBox[i]=b1->getBoxRole(i);}//格局复制
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(boxOfSide[i][j]==index)
            {
                if(getBoxHave(i)==3)
                {
                    ThreeBox=i;
                }
                else if(getBoxHave(i)==2)
                {
                    NextBox=i;
                }
            }
        }
    }
    if(deepSearchEnding(index,ThreeBox)==1)
    {
       for(int j=0;j<4;j++)
       {
           if(boxOfSide[NextBox][j]!=index&&!b1->getRole(boxOfSide[NextBox][j]))
           {
               return boxOfSide[NextBox][j];
           }
       }
    }
    else
    {
        return index;
    }
}
bool greedAi::isEndTurn()
{
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {bookBox[i]=b1->getBoxRole(i);}//格局复制
    int countBox=0;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        if(!bookBox[i])
        {
            countBox++;
            int checkBoxNum=1;
            int findLine;
            for(int j=0;j<4;j++)
            {
                findLine=boxOfSide[i][j];
                if(!b1->getRole(findLine))
                {
                    checkBoxNum+=deepSearchEnding(findLine,i);
                }
            }
        }
    }
    if(countBox==1)
        return true;
    else
        return false;
}
int greedAi::searchThisBoxList(int index)
{
    int ThreeBox;
    int NextBox;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {bookBox[i]=b1->getBoxRole(i);}//格局复制
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(boxOfSide[i][j]==index)
            {
                if(getBoxHave(i)==3)
                {
                    ThreeBox=i;
                }
                else if(getBoxHave(i)==2)
                {
                    NextBox=i;
                }
            }
        }
    }
    return deepSearchEnding(index,ThreeBox)+1;
}
int greedAi::searchSmallBoxList(int index)
{
    int MinBoxList=9999;
    int MinBoxLine=-1;
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {bookBox[i]=b1->getBoxRole(i);}//格局复制
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(boxOfSide[i][j]==index)
            {
                if(getBoxHave(i)==3)
                {
                    bookBox[i]=1;
                }
                else if(getBoxHave(i)==2)
                {
                    bookBox[i]=1;
                }
            }
        }
    }
    for(int i=0;i<CHESS_BOX_NUM;i++)
    {
        if(!bookBox[i])
        {
            int checkBoxNum=1;
            int findLine;
            for(int j=0;j<4;j++)
            {
                findLine=boxOfSide[i][j];
                if(!b1->getRole(findLine))
                {
                    checkBoxNum+=deepSearchEnding(findLine,i);
                }
            }
            qDebug()<<checkBoxNum;
            if(MinBoxList>checkBoxNum&&checkBoxNum>0)
            {
                MinBoxList=checkBoxNum;
                for(int j=0;j<4;j++)
                {
                    if(!b1->getRole(boxOfSide[i][j]))
                        MinBoxLine=boxOfSide[i][j];
                }
            }
        }
    }
    return MinBoxList;
}
