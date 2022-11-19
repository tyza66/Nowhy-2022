


#include	"Dots and Boxes.h"

/*
*主体
*/

//全局声明
NODE Square[7][7];
EDGE Horizon[6][6];											//实际上横边6x5
EDGE Vertical[6][6];										//实际上横边5x6
int myturn;
int x,y;
int Search(int deep,int alpha,int beta,int turn);
void Final_Occupy();
LIST Bestmove;
void printdegree();
int mboxes=0,yboxes=0;
int undo_type;
void undoit(int type, int x, int y);

//悔棋函数

void undoit(int type, int x, int y)							//0是横 1是竖
{
	if(type==0)





		   
	{
		Horizon[x][y].ismove=1;
		Square[x+1][y+1].degree++;
		if(Square[x+1][y+1].owner!=-1)
		{
			Square[x+1][y+1].owner=-1;
		}
		Square[x][y+1].degree++;
		if(Square[x][y+1].owner!=-1)
		{
			Square[x][y+1].owner=-1;
		}
	}
	else
	{
		Vertical[x][y].ismove=1;
		Square[x+1][y+1].degree++;
		if(Square[x+1][y+1].owner!=-1)
		{
			Square[x+1][y+1].owner=-1;
		}
		Square[x+1][y].degree++;
		if(Square[x+1][y].owner!=-1)
		{
			Square[x+1][y].owner=-1;
		}
	}

}


int FoundC()  //找到C 有C就可以封口了
{
	int i,j,k;
	for(i=1;i<6;i++)
	{
		for(j=1;j<6;j++)
		{
			if(Square[i][j].degree==1)
			{
				for(k=0;k<=3;k++)
				{
					if(Square[i][j].edge[k]->ismove==1)
					{
						Square[i][j].edge[k]->ismove=0;
						Square[i][j].degree=0;
						Square[i][j].owner=myturn;
						mboxes++;
						if(k==0)
						{
							Square[i][j-1].degree--;
							if(Square[i][j-1].degree==0)
							{
								Square[i][j-1].owner=myturn;
								mboxes++;
							}
						}
						else if(k==1)
						{
							Square[i-1][j].degree--;
							if(Square[i-1][j].degree==0)
							{
								Square[i-1][j].owner=myturn;
								mboxes++;
							}
						}
						else if(k==2)
						{
							Square[i][j+1].degree--;
							if(Square[i][j+1].degree==0)
							{
								Square[i][j+1].owner=myturn;
								mboxes++;
							}
						}
						else if(k==3)
						{
							Square[i+1][j].degree--;
							if(Square[i+1][j].degree==0)
							{
								Square[i+1][j].owner=myturn;
								mboxes++;
							}
						}

						return 1;
					}
				}
			}
		}
	}
	return 0;
}
int randmove()
{
	int i, j, k;
	int etype, x, y;    //etpye边的类型，x,y坐标
	//判断是否已经有C格，有就封上
	for(i=1;i<=6;i++)
	{
		for(j=1;j<=6;j++)
		{
			if(Square[i][j].degree==1)
			{
				for(k=0;k<=3;k++)
				{
					if(Square[i][j].edge[k]->ismove==1)
					{
						Square[i][j].edge[k]->ismove=0;
						Square[i][j].degree=0;
						Square[i][j].owner=myturn;
						mboxes++;
						if(k==0)
						{
							Square[i][j-1].degree--;
							if(Square[i][j-1].degree==0)
							{
								Square[i][j-1].owner=myturn;
								mboxes++;
							}
						}
						else if(k==1)
						{
							Square[i-1][j].degree--;
							if(Square[i-1][j].degree==0)
							{
								Square[i-1][j].owner=myturn;
								mboxes++;
							}
						}
						else if(k==2)
						{
							Square[i][j+1].degree--;
							if(Square[i][j+1].degree==0)
							{
								Square[i][j+1].owner=myturn;
								mboxes++;
							}
						}
						else if(k==3)
						{
							Square[i+1][j].degree--;
							if(Square[i+1][j].degree==0)
							{
								Square[i+1][j].owner=myturn;
								mboxes++;
							}
						}
						randmove();
						return 0;
					}
				}
			}
		}
	}

	srand((unsigned)time(NULL));
	for(i=0;;i++)
	{
		etype=rand()%2;     //0横边，1竖边
		
		
		if(etype==0)
		{
			x=rand()%6;
			y=rand()%5;
		}
		else
		{
			x=rand()%5;
			y=rand()%6;
		}
		
		
		if((etype==0&&Horizon[x][y].ismove==0)||(etype==1&&Vertical[x][y].ismove==0))
		{	
			continue;
		}
		else if(etype==0&&(Square[x][y+1].degree==2||Square[x+1][y+1].degree==2))//注意，判断C格出现。
			{
				continue;
			}		
		else if(etype==1&&(Square[x+1][y].degree==2||Square[x+1][y+1].degree==2))
			{
				continue;
			}
		else
			break;

	}                    
	
	if(etype==0)
	{
		Horizon[x][y].ismove=0;
		Square[x][y+1].degree--;
		Square[x+1][y+1].degree--;
	}
	else
	{
		Vertical[x][y].ismove=0;
		Square[x+1][y].degree--;
		Square[x+1][y+1].degree--;
	}
	printf("%d %d %d\n",etype,x,y);
	return  0;
}



void put()
{
	int i, j;
	for(i=0;i<=10;i++)
	{
		if(i%2==0)
		{
			for(j=0;j<=10;j++)
			{
				if(j%2==0)
				{
					printf("%c%c", -95, -15);
				}
				else
				{
					if(Horizon[i/2][j/2].ismove==1)
					{
						printf("    ");
					}
					else
					{
						printf("%c%c", -95, -86);
						printf("%c%c", -95, -86);
					}
				}
			}
			printf("\n");
		}
		else
		{
			for(j=0;j<=10;j++)
			{
				if(j%2==0)
				{
					if(Vertical[i/2][j/2].ismove==1)
					{
						printf(" ");
					}
					else
					{
						printf("%c", 124);
					}
				}
				else
				{
					if(Square[i/2+1][(j+1)/2].owner!=-1)
					{
						printf("  %d  ",Square[i/2+1][(j+1)/2].owner);
					}
					else
					{
						printf("     ");
					}
				}
			}
			printf("\n");

			for(j=0;j<=10;j++)
			{
				if(j%2==0)
				{
					if(Vertical[i/2][j/2].ismove==1)
					{
						printf(" ");
					}
					else
					{
						printf("%c", 124);
					}
				}
				else
				{
					if(Square[i/2+1][(j+1)/2].owner!=-1)
					{
						printf("  %d  ",Square[i/2+1][(j+1)/2].owner);
					}
					else
					{
						printf("     ");
					}
				}
			}
			printf("\n");
		}
	}
	printf("\n—————————————————\n\n");
}

//某一步棋走后是否捕获格子,是返回1；否返回0
int Iscapture(int HorV ,int x,int y,int turn)               //turn表示该方刚下的子，判断是否占领格子													
{
	int flag=0;
	if(HorV==0)
	{
		if(Square[x+1][y+1].degree==0)						
		{
			
			Square[x+1][y+1].owner=turn;
			if(turn==myturn)
			{
				mboxes++;
			}
			else
			{
				yboxes++;
			}
			flag=1;
		}
		if(Square[x][y+1].degree==0)
		{
			Square[x][y+1].owner=turn;
			if(turn==myturn)
			{
				mboxes++;
			}
			else
			{
				yboxes++;
			}
			flag=1;
		}
		if(flag==1)//被捕获
		{
			return 1;

		}
		//未被捕获
		return 0;
	}
	else
	{
		if(Square[x+1][y].degree==0)
		{
			Square[x+1][y].owner=turn;
			if(turn==myturn)
			{
				mboxes++;
			}
			else
			{
				yboxes++;
			}
			flag=1;
		}
		if(Square[x+1][y+1].degree==0)
		{
			Square[x+1][y+1].owner=turn;
			if(turn==myturn)
			{
				mboxes++;
			}
			else
			{
				yboxes++;
			}
			flag=1;
		}
		if(flag==1)
			return 1;
		else
			return 0;
	}
}

bool IsDeadGridEdge()                         //判断是否任何一条边下上去都是死格，
											//若是返回true，即任何一步都会形成一死格,不能给对手留机会
											//否，返回false。
{
	int i, j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			if(i!=5)
			{
				if(Vertical[i][j].ismove==1)
				{
					if(Square[i+1][j].degree>2&&Square[i+1][j+1].degree>2)
					{
						return false;
					}
				}
			}
			if(j!=5)
			{
				if(Horizon[i][j].ismove==1)
				{
					if(Square[i][j+1].degree>2&&Square[i+1][j+1].degree>2)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}


int main()
{
	int op;                                                             //对方刚刚下的是哪一种边（横或竖）
	int count1,count2;													//横边或竖边的位置
	int HorV;															
	int i,j,k;															//循环中用来计数
	int times;															
	int flag=0;
	for(i=1;i<6;i++)
	{
		for(j=1;j<6;j++)
		{
		Square[i][j].degree=4;
		Square[i][j].x=i;
		Square[i][j].y=j;
		Square[i][j].owner=-1;											//未被占领
		Square[i][j].ground=1;
		Square[i][j].edge[0]=&Vertical[i-1][j-1];
		Square[i][j].edge[2]=&Vertical[i-1][j];
		Square[i][j].edge[1]=&Horizon[i-1][j-1];
		Square[i][j].edge[3]=&Horizon[i][j-1];
		for(k=0;k<4;k++)
		{
			
			Square[i][j].edge[k]->ismove=1;
			Square[i][j].edge[k]->length=1;

		}
		}
	}
	for(i=0;i<7;i++)
	{
		Square[0][i].ground=0;
		Square[i][0].ground=0;
		Square[6][i].ground=0;
		Square[i][6].ground=0;
		Square[0][i].degree=3;
		Square[i][0].degree=3;
		Square[6][i].degree=3;
		Square[i][6].degree=3;

	}
	while(1)
	{
		scanf("%d",&myturn);												//0代表先手，1代表后手 第一个输入是先后手
		if(myturn==0)														//我方先手
		{
			randmove();
			times=2;	//?????????
			put();
			break;
		/*	//Square[5][4].edge[2]->ismove=0;									//下第一步
			//Square[5][5].edge[0]->ismove=0;
			Square[5][4].degree--;
			Square[5][5].degree--;
			Vertical[4][4].ismove=0;
			
			*/
		}
		else if(myturn==1)													//我方后手
		{
			times=1;
			break;
		}

	}
	while(1)
	{
		scanf("%d%d%d",&op,&count1,&count2);						//输入边的类型和坐标 坐标从0开始
		if(op==0)											//对方连接的是横边，0代表横边，1代表竖边
		{
			//Square[count1][count2+1].edge[3]->ismove=0;
			//Square[count1+1][count2+1].edge[1]->ismove=0;
			Square[count1][count2+1].degree--;
			Square[count1+1][count2+1].degree--;
			Horizon[count1][count2].ismove=0;
			
		}
		else if(op==1)										//对方连接的是竖边
		{
			//Square[count1+1][count2].edge[2]->ismove=0;
			//Square[count1+1][count2+1].edge[0]->ismove=0;
			Square[count1+1][count2].degree--;
			Square[count1+1][count2+1].degree--;
			Vertical[count1][count2].ismove=0;
		}
		else
		{
			scanf("%d",&undo_type);
			undoit(undo_type,count1,count2);
			put();
			continue;
		}
		
		//打印对方下一步子形成的局面
		
		if(Iscapture(op,count1,count2,!myturn))			//判断对方是否获得格子，是，则返回继续读入对方棋子
		{
			put();
			continue;
		}
		else
		{
			put();
			if(flag==1)
			{
				Final_Occupy();
				continue;
			}
			
			if(times<8)
			{

				randmove();
				times++;
				put();
				continue;
			}
			
myside:		if(IsDeadGridEdge())
			{
				printf("begin\n");
				//printdegree();
				flag=1;
				Final_Occupy();//包含打印棋盘
				continue;
			}
			else
			{
			while(FoundC())  //返回1代表有C格，封上后打印棋盘再判断是否还有
			{
				put();
			}
			Search(1,-1200,1200,myturn);
			HorV=Bestmove.move_type;
			x=Bestmove.move_hor;
			y=Bestmove.move_ver;
			//边加入，即在该棋盘中边消除
			if(HorV==0)												//返回0表示	的是添加的是横边							
			{
				Horizon[x][y].ismove=0;
				//Square[x+1][y+1].edge[1]->ismove=0;
				//Square[x][y+1].edge[3]->ismove=0;
				Square[x+1][y+1].degree--;
				Square[x][y+1].degree--;
			}
			else														//竖边
			{
				Vertical[x][y].ismove=0;
				//Square[x+1][y].edge[2]->ismove=0;
				//Square[x+1][y+1].edge[0]->ismove=0;
				Square[x+1][y].degree--;
				Square[x+1][y+1].degree--;
			}
			
			printf("%d %d %d\n",HorV,x,y);	
			if(Iscapture(HorV,x,y,myturn))                  //我方下子占领格子，返回Search搜索下一步
			{												//直到下子后不占领格子，返回对方下子
				put();								
				goto myside;
			}
				
			
			put();//打印我方下一步子形成的局面

			continue;
			}
		}
	}
	return 0;
}







void printdegree()
{
	int i,j;
	for(i=1;i<6;i++)
	{
		for(j=1;j<6;j++)
		{
			printf("%d\n",Square[i][j].degree);
		}

	}
}