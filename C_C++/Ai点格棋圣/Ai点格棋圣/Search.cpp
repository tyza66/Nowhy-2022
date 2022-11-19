

#include   "Search.h"



int Search(int deep,int alpha,int beta,int turn)
{
	int score,MAX=0,MIN=0;
	int HorV;
	int len;
	int i,j;
	int x,y;
	LIST Movelist[61];									//储存招法的数组
	len=move(Movelist);											//招法生成
	

	if(deep==1)
	{
		printf("%d\n",len);
		leni=len;
	}

	//if(len>Max_len&&deep==1)
	//{
	//	Num_Move=0;
	//}
	//if(len<=Max_len&&deep==1)
	//{
	//	Num_Move=1;
	//}

	if(leni>Max_len)
	{
		if(deep==Max_deep)
		{

			return Evaluation(turn);  //返回-50或50或。。。。
	
		}
	}
	if(leni<=Max_len) 
	{
		alpha=-50;beta=50;
		if(IsDeadGridEdge())
		{
			return Evaluation(turn);
		}
	}

	if(turn==myturn)                                      //我方下子，取极大值
	{
		for(i=0;i<len;i++)
		{
			
			HorV=Movelist[i].move_type;
			
			if(HorV==0)								//招法表示在棋盘上
			{
				x=Movelist[i].move_hor;
				y=Movelist[i].move_ver;
				//Square[x+1][y+1].edge[1]->ismove=0;
				//Square[x][y+1].edge[3]->ismove=0;
				Square[x+1][y+1].degree--;
				Square[x][y+1].degree--;
				Horizon[x][y].ismove=0;
			}
			else
			{
				x=Movelist[i].move_hor;
				y=Movelist[i].move_ver;
				//Square[x+1][y].edge[2]->ismove=0;
				//Square[x+1][y+1].edge[0]->ismove=0;
				Square[x+1][y].degree--;
				Square[x+1][y+1].degree--;
				Vertical[x][y].ismove=0;
			}
			//if(deep!=Max_deep-1) //倒数第二层，不需要换手
			//{
				//if(!Iscapture(HorV,x,y,turn))			//该步未占领格子，换另一方下子
				//{
			//		turn=!turn;
				//}
			//}
			

				
			score=Search(deep+1,alpha,beta,!turn);
													
			
			//撤销招法
			if(HorV==0)
			{
				//Square[x+1][y+1].edge[1]->ismove=1;
				//Square[x][y+1].edge[3]->ismove=1;
				Square[x+1][y+1].degree++;
				Square[x][y+1].degree++;
				Square[x+1][y+1].owner=-1;
				Square[x][y+1].owner=-1;
				Horizon[x][y].ismove=1;

			}
			else
			{
				//Square[x+1][y+1].edge[0]->ismove=1;
				//Square[x+1][y].edge[2]->ismove=1;
				Square[x+1][y+1].owner=-1;
				Square[x+1][y].owner=-1;
				Square[x+1][y+1].degree++;
				Square[x+1][y].degree++;
				Vertical[x][y].ismove=1;
			}
			if(leni>Max_len&&deep==Max_deep-1)
			{
				MAX+=score;
				score=MAX;
				if(i!=len-1)
					continue;
			}
			
			if(score>=alpha)
			{
				alpha=score;
				if(deep==1)
				{
					Bestmove=Movelist[i];
				}
			
			if(alpha>=beta)
			{
				return beta;		//beta剪枝
			}
}
		}	
			return alpha;
	}
	else
	{
		for(j=0;j<len;j++)
		{
			
			HorV=Movelist[j].move_type;
			
			if(HorV==0)
			{
				x=Movelist[j].move_hor;
				y=Movelist[j].move_ver;
				//Square[x+1][y+1].edge[1]->ismove=0;
				//Square[x][y+1].edge[3]->ismove=0;
				Square[x+1][y+1].degree--;
				Square[x][y+1].degree--;
				Horizon[x][y].ismove=0;
			}
			else
			{
				x=Movelist[j].move_hor;
				y=Movelist[j].move_ver;
			//	Square[x+1][y].edge[2]->ismove=0;
			//	Square[x+1][y+1].edge[0]->ismove=0;
				Square[x+1][y].degree--;
				Square[x+1][y+1].degree--;
				Vertical[x][y].ismove=0;
			}
			
			//if(deep!=Max_deep-1)
			//{
				//if(Iscapture(HorV,x,y,turn)==0)
			//{
			//	turn=!turn;
			//}
			//}
			
			score=Search(deep+1,alpha,beta,!turn);

			if(HorV==0)
			{
				//Square[x+1][y+1].edge[1]->ismove=1;
				//Square[x][y+1].edge[3]->ismove=1;
				Square[x+1][y+1].degree++;
				Square[x][y+1].degree++;
				Square[x+1][y+1].owner=-1;
				Square[x][y+1].owner=-1;
				Horizon[x][y].ismove=1;
			}
			else
			{
				//Square[x+1][y+1].edge[0]->ismove=1;
				//Square[x+1][y].edge[2]->ismove=1;
				Square[x+1][y+1].degree++;
				Square[x+1][y+1].owner=-1;
				Square[x+1][y].degree++;
				Square[x+1][y].owner=-1;
				Vertical[x][y].ismove=1;
			}
			
			if(leni>Max_len&&deep==Max_deep-1)
			{
				MIN+=score;
				score=MIN;
				if(j!=len-1)
					continue;
			}

			if(score<=beta)
			{
				beta=score;
			}
			if(alpha>=beta)
			{
				return alpha;	//alpha剪枝
			}
		}
		return beta;
	}
}



	/*score=0;
		if(turn==myturn)
		{
			for(i=0;i<len;i++)
			{
				
				Eval=Evaluation(turn);
				if(Eval==50)
				{
					score+=50;
				}
			}
			return score;
		}
		else
		{
			for(i=0;i<len;i++)
			{
				Eval=Evaluation(!turn);
				if()
			}
		}*/

/*int GameOver()
{
		
	int k,l;
		for(k=1;k<=5;k++)
		{
			for(l=1;l<=5;l++)
			{
				if(Square[k][l].owner==-1)
				{
					return 0;
				}
			}
		}
		return 1;
}*/ 










