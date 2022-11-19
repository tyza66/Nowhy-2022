#include "Evaluate.h"

//此文件全局

int Searched[7][7];

int SingleChain(int x, int y)               //判断单链的情况
{
	if(x==1&&y==1)            //左上
	{
		if(Square[x][y].edge[2]->ismove==0&&Square[x][y].edge[3]->ismove==0&&Square[x][y].degree==2)
		{
			Searched[x][y]=1;
			return 1;
		}
	}
	if(x==1&&y==5)            //右上
	{
		if(Square[x][y].edge[0]->ismove==0&&Square[x][y].edge[3]->ismove==0&&Square[x][y].degree==2)
		{
			Searched[x][y]=1;
			return 1;
		}
	}
	if(x==5&&y==1)            //左下
	{
		if(Square[x][y].edge[1]->ismove==0&&Square[x][y].edge[2]->ismove==0&&Square[x][y].degree==2)
		{
			Searched[x][y]=1;
			return 1;
		}
	}
	if(x==5&&y==5)            //左下
	{
		if(Square[x][y].edge[0]->ismove==0&&Square[x][y].edge[1]->ismove==0&&Square[x][y].degree==2)
		{
			Searched[x][y]=1;
			return 1;
		}
	}
	return 0;
}




int DoubleChain(int x, int y)                       //判断双链的情况
{
	if(x==1&&y>=1&&y<=4)											//上边
	{
		if(Square[x][y].edge[1]->ismove==1&&Square[x][y].edge[2]->ismove==1&&Square[x][y].degree==2)
		{
			if(Square[x][y+1].edge[1]->ismove==1&&Square[x][y+1].degree==2)
			{
				Searched[x][y]=1;
				Searched[x][y+1]=1;
				return 1;
			}
		}
	}
	if(x==5&&y>=1&&y<=4)											//下边
	{
		if(Square[x][y].edge[3]->ismove==1&&Square[x][y].edge[2]->ismove==1&&Square[x][y].degree==2)
		{
			if(Square[x][y+1].edge[3]->ismove==1&&Square[x][y+1].degree==2)
			{
				Searched[x][y]=1;
				Searched[x][y+1]=1;
				return 1;
			}
		}
	}
	if(y==1&&x>=1&&x<=4)											//左边
	{
		if(Square[x][y].edge[0]->ismove==1&&Square[x][y].edge[3]->ismove==1&&Square[x][y].degree==2)
		{
			if(Square[x+1][y].edge[0]->ismove==1&&Square[x+1][y].degree==2)
			{
				Searched[x][y]=1;
				Searched[x+1][y]=1;
				return 1;
			}
		}
	}
	if(y==5&&x>=1&&x<=4)											//右边
	{
		if(Square[x][y].edge[2]->ismove==1&&Square[x][y].edge[3]->ismove==1&&Square[x][y].degree==2)
		{
			if(Square[x+1][y].edge[2]->ismove==1&&Square[x+1][y].degree==2)
			{
				Searched[x][y]=1;
				Searched[x+1][y]=1;
				return 1;
			}
		}
	}	


	if(x==1&&y==1)                                                   //左上角
	{
		if(Square[1][1].edge[1]->ismove==1&&Square[1][1].edge[3]->ismove==1&&Square[1][1].degree==2)
		{
			if(Square[2][1].edge[0]->ismove==1&&Square[2][1].degree==2)
			{
				Searched[2][1]=1;
				Searched[x][y]=1;
				return 1;
			}
		}
		if(Square[1][1].edge[0]->ismove==1&&Square[1][1].edge[2]->ismove==1&&Square[1][1].degree==2)
		{
			if(Square[1][2].edge[1]->ismove==1&&Square[1][2].degree==2)
			{
				Searched[1][2]=1;
				Searched[x][y]=1;
				return 1;
			}
		}
	}

	if(x==1&&y==5)                                                   //右上角
	{
		if(Square[1][5].edge[2]->ismove==1&&Square[1][5].edge[0]->ismove==1&&Square[1][5].degree==2)
		{
			if(Square[1][4].edge[1]->ismove==1&&Square[1][4].degree==2)
			{
				Searched[1][4]=1;
				Searched[x][y]=1;
				return 1;
			}
		}
		if(Square[1][5].edge[1]->ismove==1&&Square[1][5].edge[3]->ismove==1&&Square[1][5].degree==2)
		{
			if(Square[2][5].edge[2]->ismove==1&&Square[2][5].degree==2)
			{
				Searched[2][5]=1;
				Searched[x][y]=1;
				return 1;
			}
		}
	}

	if(x==5&&y==1)                                                   //左下角
	{
		if(Square[5][1].edge[3]->ismove==1&&Square[5][1].edge[1]->ismove==1&&Square[5][1].degree==2)
		{
			if(Square[4][1].edge[0]->ismove==1&&Square[4][1].degree==2)
			{
				Searched[4][1]=1;
				Searched[x][y]=1;
				return 1;
			}
		}
		if(Square[5][1].edge[0]->ismove==1&&Square[5][1].edge[2]->ismove==1&&Square[5][1].degree==2)
		{
			if(Square[5][2].edge[3]->ismove==1&&Square[5][2].degree==2)
			{
				Searched[5][2]=1;
				Searched[x][y]=1;
				return 1;
			}
		}
	}

	if(x==5&&y==5)                                                   //右下角
	{
		if(Square[5][5].edge[1]->ismove==1&&Square[5][5].edge[3]->ismove==1&&Square[5][5].degree==2)
		{
			if(Square[4][5].edge[2]->ismove==1&&Square[4][5].degree==2)
			{
				Searched[4][5]=1;
				Searched[x][y]=1;
				return 1;
			}
		}
		if(Square[5][5].edge[0]->ismove==1&&Square[5][5].edge[2]->ismove==1&&Square[5][5].degree==2)
		{
			if(Square[5][4].edge[3]->ismove==1&&Square[5][4].degree==2)
			{
				Searched[5][4]=1;
				Searched[x][y]=1;
				return 1;
			}
		}
	}
	return 0;
}


int Triple_Freedom(int x, int y)                //判断某三自由度格的情况
{
	if(Square[x][y].degree==3)									//找到此三自由度格子
	{
		if(Square[x][y].edge[0]->ismove==1)						//找到此自由个字的无边方向 若为左边
		{
			if(Square[x][y-1].degree==2&&y-1>0&&!Searched[x][y-1])						//临近三个格子自由度都为二 则不是反双交
			{
				if(Square[x][y-1].edge[0]->ismove==1)
				{
					if((Square[x][y-2].degree==3||Square[x][y-2].degree==4)&&y-2>0&&!Searched[x][y-2])
					{
						Searched[x][y]=1;
						Searched[x][y-1]=1;
						Searched[x][y-2]=1;
						return 1;
					}
					if(Square[x][y-2].degree==2&&y-2>0&&!Searched[x][y-2])					
					{
						if(Square[x][y-2].edge[0]->ismove==1)
						{
							if(Square[x][y-3].degree==3||Square[x][y-3].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y-1]=1;
								Searched[x][y-2]=1;
								Searched[x][y-3]=1;
								return 1;
							}					
						}
						if(Square[x][y-2].edge[1]->ismove==1)
						{
							if(Square[x-1][y-2].degree==3||Square[x-1][y-2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y-1]=1;
								Searched[x][y-2]=1;
								Searched[x-1][y-2]=1;
								return 1;
							}					
						}
						if(Square[x][y-2].edge[3]->ismove==1)
						{
							if(Square[x+1][y-2].degree==3||Square[x+1][y-2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y-1]=1;
								Searched[x][y-2]=1;
								Searched[x+1][y-2]=1;
								return 1;
							}					
						}
					}
				}
				if(Square[x][y-1].edge[1]->ismove==1)
				{
					if((Square[x-1][y-1].degree==3||Square[x-1][y-1].degree==4)&&x-1>0&&!Searched[x-1][y-1])
					{
						Searched[x][y]=1;
						Searched[x][y-1]=1;
						Searched[x-1][y-1]=1;
						return 1;
					}
					if(Square[x-1][y-1].degree==2&&x-1>0&&!Searched[x-1][y-1])				
					{
						if(Square[x-1][y-1].edge[0]->ismove==1)
						{
							if(Square[x-1][y-2].degree==3||Square[x-1][y-2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y-1]=1;
								Searched[x-1][y-1]=1;
								Searched[x-1][y-2]=1;
								return 1;
							}					
						}
						if(Square[x-1][y-1].edge[1]->ismove==1)
						{
							if(Square[x-2][y-1].degree==3||Square[x-2][y-1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y-1]=1;
								Searched[x-1][y-1]=1;
								Searched[x-2][y-1]=1;
								return 1;
							}					
						}
						if(Square[x-1][y-1].edge[2]->ismove==1)
						{
							if(Square[x-1][y].degree==3||Square[x-1][y].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y-1]=1;
								Searched[x-1][y-1]=1;
								Searched[x-1][y]=1;
								return 1;
							}					
						}
					}
				}
				if(Square[x][y-1].edge[3]->ismove==1)
				{
					if((Square[x+1][y-1].degree==3||Square[x+1][y-1].degree==4)&&x+1<6&&!Searched[x+1][y-1])
					{
						Searched[x][y]=1;
						Searched[x][y-1]=1;
						Searched[x+1][y-1]=1;
						return 1;
					}
					if(Square[x+1][y-1].degree==2&&x+1<6&&!Searched[x+1][y-1])				
					{
						if(Square[x+1][y-1].edge[0]->ismove==1)
						{
							if(Square[x+1][y-2].degree==3||Square[x+1][y-2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y-1]=1;
								Searched[x+1][y-1]=1;
								Searched[x+1][y-2]=1;
								return 1;
							}					
						}
						if(Square[x+1][y-1].edge[2]->ismove==1)
						{
							if(Square[x+1][y].degree==3||Square[x+1][y].degree==4)           
							{
								Searched[x][y]=1;
								Searched[x][y-1]=1;
								Searched[x+1][y-1]=1;
								Searched[x+1][y]=1;
								return 1;
							}					
						}
						if(Square[x+1][y-1].edge[3]->ismove==1)
						{
							if(Square[x+2][y-1].degree==3||Square[x+2][y-1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y-1]=1;
								Searched[x+1][y-1]=1;
								Searched[x+2][y-1]=1;
								return 1;
							}					
						}
					}
				}
			}
		}
		if(Square[x][y].edge[1]->ismove==1)						//找到此自由个字的无边方向 若为上边
		{
			if(Square[x-1][y].degree==2&&x-1>0&&!Searched[x-1][y])						//临近三个格子自由度都为二 则不是反双交
			{
				if(Square[x-1][y].edge[0]->ismove==1)
				{
					if((Square[x-1][y-1].degree==3||Square[x-1][y-2].degree==4)&&y-1>0&&!Searched[x-1][y-1])
					{
						Searched[x][y]=1;
						Searched[x-1][y]=1;
						Searched[x-1][y-1]=1;
						return 1;
					}
					if(Square[x-1][y-1].degree==2&&y-1>0&&!Searched[x-1][y-1])					
					{
						if(Square[x-1][y-1].edge[0]->ismove==1)                        //hhkjhkjlhlkjhfaksdjhlasd
						{
							if(Square[x-1][y-2].degree==3||Square[x-1][y-2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x-1][y]=1;
								Searched[x-1][y-1]=1;
								Searched[x-1][y-2]=1;
								return 1;
							}					
						}
						if(Square[x-1][y-1].edge[1]->ismove==1)
						{
							if(Square[x-2][y-1].degree==3||Square[x-2][y-1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x-1][y]=1;
								Searched[x-1][y-1]=1;
								Searched[x-2][y-1]=1;
								return 1;
							}					
						}
						if(Square[x-1][y-1].edge[3]->ismove==1)
						{
							if(Square[x][y-1].degree==3||Square[x][y-1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x-1][y]=1;
								Searched[x-1][y-1]=1;
								Searched[x][y-1]=1;
								return 1;
							}					
						}
					}
				}
				if(Square[x-1][y].edge[1]->ismove==1)
				{
					if((Square[x-2][y].degree==3||Square[x-2][y].degree==4)&&x-2>0&&!Searched[x-2][y])
					{
						Searched[x][y]=1;
						Searched[x-1][y]=1;
						Searched[x-2][y]=1;
						return 1;
					}
					if(Square[x-2][y].degree==2&&x-2>0&&!Searched[x-2][y])					
					{
						if(Square[x-2][y].edge[0]->ismove==1)
						{
							if(Square[x-2][y-1].degree==3||Square[x-2][y-1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x-1][y]=1;
								Searched[x-2][y]=1;
								Searched[x-2][y-1]=1;
								return 1;
							}					
						}
						if(Square[x-2][y].edge[1]->ismove==1)
						{
							if(Square[x-3][y].degree==3||Square[x-3][y].degree==4)
							{
								Searched[x][y]=1;
								Searched[x-1][y]=1;
								Searched[x-2][y]=1;
								Searched[x-3][y]=1;
								return 1;
							}					
						}
						if(Square[x-2][y].edge[2]->ismove==1)
						{
							if(Square[x-2][y+1].degree==3||Square[x-2][y+1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x-1][y]=1;
								Searched[x-2][y]=1;
								Searched[x-2][y+1]=1;
								return 1;
							}					
						}
					}
				}
				if(Square[x-1][y].edge[2]->ismove==1)
				{
					if((Square[x-1][y+1].degree==3||Square[x-1][y+1].degree==4)&&y+1<6&&!Searched[x-1][y+1])
					{
						Searched[x][y]=1;
						Searched[x-1][y]=1;
						Searched[x-1][y+1]=1;
						return 1;
					}
					if(Square[x-1][y+1].degree==2&&y+1<6&&!Searched[x-1][y+1])					
					{
						if(Square[x-1][y+1].edge[3]->ismove==1)
						{
							if(Square[x][y+1].degree==3||Square[x][y+1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x-1][y]=1;
								Searched[x-1][y+1]=1;
								Searched[x][y+1]=1;
								return 1;
							}					
						}
						if(Square[x-1][y+1].edge[1]->ismove==1)
						{
							if(Square[x-2][y+1].degree==3||Square[x-2][y+1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x-1][y]=1;
								Searched[x-1][y+1]=1;
								Searched[x-2][y+1]=1;
								return 1;
							}					
						}
						if(Square[x-1][y+1].edge[2]->ismove==1)
						{
							if(Square[x-1][y+2].degree==3||Square[x-1][y+2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x-1][y]=1;
								Searched[x-1][y+1]=1;
								Searched[x-1][y+2]=1;
								return 1;
							}					
						}
					}
				}
			}
		}
		if(Square[x][y].edge[2]->ismove==1)						//找到此自由个字的无边方向 若为右边
		{
			if(Square[x][y+1].degree==2&&y+1<6&&!Searched[x][y+1])						//临近三个格子自由度都为二 则不是反双交
			{
				if(Square[x][y+1].edge[1]->ismove==1)
				{
					if((Square[x-1][y+1].degree==3||Square[x-1][y+1].degree==4)&&x-1>0&&!Searched[x-1][y+1])
					{
						Searched[x][y]=1;
						Searched[x][y+1]=1;
						Searched[x-1][y+1]=1;
						return 1;
					}
					if(Square[x-1][y+1].degree==2&&x-1>0&&!Searched[x-1][y+1])					
					{
						if(Square[x-1][y+1].edge[1]->ismove==1)
						{
							if(Square[x-2][y+1].degree==3||Square[x-2][y+1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y+1]=1;
								Searched[x-1][y+1]=1;
								Searched[x-2][y+1]=1;
								return 1;
							}					
						}
						if(Square[x-1][y+1].edge[2]->ismove==1)
						{
							if(Square[x-1][y+2].degree==3||Square[x-1][y+2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y+1]=1;
								Searched[x-1][y+1]=1;
								Searched[x-1][y+2]=1;
								return 1;
							}					
						}
						if(Square[x-1][y+1].edge[0]->ismove==1)
						{
							if(Square[x-1][y].degree==3||Square[x-1][y].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y+1]=1;
								Searched[x-1][y+1]=1;
								Searched[x-1][y]=1;
								return 1;
							}					
						}
					}
				}
				if(Square[x][y+1].edge[2]->ismove==1)
				{
					if((Square[x][y+2].degree==3||Square[x][y+2].degree==4)&&y+2<6&&!Searched[x][y+2])
					{						
						Searched[x][y]=1;
						Searched[x][y+1]=1;
						Searched[x][y+2]=1;
						return 1;
					}
					if(Square[x][y+2].degree==2&&y+2<6&&!Searched[x][y+2])					
					{
						if(Square[x][y+2].edge[1]->ismove==1)
						{
							if(Square[x-1][y+2].degree==3||Square[x-1][y+2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y+1]=1;
								Searched[x][y+2]=1;
								Searched[x-1][y+2]=1;
								return 1;
							}					
						}
						if(Square[x][y+2].edge[2]->ismove==1)
						{
							if(Square[x][y+3].degree==3||Square[x][y+3].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y+1]=1;
								Searched[x][y+2]=1;
								Searched[x][y+3]=1;
								return 1;
							}					
						}
						if(Square[x][y+2].edge[3]->ismove==1)
						{
							if(Square[x+1][y+2].degree==3||Square[x+1][y+2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y+1]=1;
								Searched[x][y+2]=1;
								Searched[x+1][y+2]=1;
								return 1;
							}					
						}
					}
				}
				if(Square[x][y+1].edge[3]->ismove==1)
				{
					if((Square[x+1][y+1].degree==3||Square[x+1][y+1].degree==4)&&x+1<6&&!Searched[x+1][y+1])
					{
						Searched[x][y]=1;
						Searched[x][y+1]=1;
						Searched[x+1][y+1]=1;
						return 1;
					}
					if(Square[x+1][y+1].degree==2&&x+1<6&&!Searched[x+1][y+1])					
					{
						if(Square[x+1][y+1].edge[0]->ismove==1)
						{
							if(Square[x+1][y].degree==3||Square[x+1][y].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y+1]=1;
								Searched[x+1][y+1]=1;
								Searched[x+1][y]=1;
								return 1;
							}					
						}
						if(Square[x+1][y+1].edge[2]->ismove==1)
						{
							if(Square[x+1][y+2].degree==3||Square[x+1][y+2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y+1]=1;
								Searched[x+1][y+1]=1;
								Searched[x+1][y+2]=1;
								return 1;
							}					
						}
						if(Square[x+1][y+1].edge[3]->ismove==1)
						{
							if(Square[x+2][y+1].degree==3||Square[x+2][y+1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x][y+1]=1;
								Searched[x+1][y+1]=1;
								Searched[x+2][y+1]=1;
								return 1;
							}					
						}
					}
				}
			}
		}
		if(Square[x][y].edge[3]->ismove==1)						//找到此自由个字的无边方向 若为下边
		{
			if(Square[x+1][y].degree==2&&x+1<6&&!Searched[x+1][y])						//临近三个格子自由度都为二 则不是反双交
			{
				if(Square[x+1][y].edge[0]->ismove==1)
				{
					if((Square[x+1][y-1].degree==3||Square[x+1][y-1].degree==4)&&y-1>0&&!Searched[x+1][y-1])
					{
						Searched[x][y]=1;
						Searched[x+1][y]=1;
						Searched[x+1][y-1]=1;
						return 1;
					}
					if(Square[x+1][y-1].degree==2&&y-1>0&&!Searched[x+1][y-1])					
					{
						if(Square[x+1][y-1].edge[0]->ismove==1)
						{
							if(Square[x+1][y-2].degree==3||Square[x+1][y-2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x+1][y]=1;
								Searched[x+1][y-1]=1;
								Searched[x+1][y-2]=1;
								return 1;
							}
						}
						if(Square[x+1][y-1].edge[1]->ismove==1)
						{
							if(Square[x][y-1].degree==3||Square[x][y-1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x+1][y]=1;
								Searched[x+1][y-1]=1;
								Searched[x][y-1]=1;
								return 1;
							}
						}
						if(Square[x+1][y-1].edge[3]->ismove==1)
						{
							if(Square[x+2][y-1].degree==3||Square[x+2][y-1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x+1][y]=1;
								Searched[x+1][y-1]=1;
								Searched[x+2][y-1]=1;
								return 1;
							}
						}
					}
				}
				if(Square[x+1][y].edge[2]->ismove==1)
				{
					if((Square[x+1][y+1].degree==3||Square[x+1][y+1].degree==4)&&y+1<6&&!Searched[x+1][y+1])
					{
						Searched[x][y]=1;
						Searched[x+1][y]=1;
						Searched[x+1][y+1]=1;
						return 1;
					}
					if(Square[x+1][y+1].degree==2&&y+1<6&&!Searched[x+1][y+1])					
					{
						if(Square[x+1][y+1].edge[1]->ismove==1)
						{
							if(Square[x][y+1].degree==3||Square[x][y+1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x+1][y]=1;
								Searched[x+1][y+1]=1;
								Searched[x][y+1]=1;
								return 1;
							}
						}
						if(Square[x+1][y+1].edge[2]->ismove==1)
						{
							if(Square[x+1][y+2].degree==3||Square[x+1][y+2].degree==4)
							{
								Searched[x][y]=1;
								Searched[x+1][y]=1;
								Searched[x+1][y+1]=1;
								Searched[x+1][y+2]=1;
								return 1;
							}
						}
						if(Square[x+1][y+1].edge[3]->ismove==1)
						{
							if(Square[x+2][y+1].degree==3||Square[x+2][y+1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x+1][y]=1;
								Searched[x+1][y+1]=1;
								Searched[x+2][y+1]=1;
								return 1;
							}
						}
					}
				}
				if(Square[x+1][y].edge[3]->ismove==1)
				{
					if((Square[x+2][y].degree==3||Square[x+2][y].degree==4)&&x+2<6&&!Searched[x+2][y])
					{						
						Searched[x][y]=1;
						Searched[x+1][y]=1;
						Searched[x+2][y]=1;
						return 1;
					}
					if(Square[x+2][y].degree==2&&x+2<6&&!Searched[x+2][y])			
					{
						if(Square[x+2][y].edge[0]->ismove==1)
						{
							if(Square[x+2][y-1].degree==3||Square[x+2][y-1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x+1][y]=1;
								Searched[x+2][y]=1;
								Searched[x+2][y-1]=1;
								return 1;
							}
						}
						if(Square[x+2][y].edge[2]->ismove==1)
						{
							if(Square[x+2][y+1].degree==3||Square[x+2][y+1].degree==4)
							{
								Searched[x][y]=1;
								Searched[x+1][y]=1;
								Searched[x+2][y]=1;
								Searched[x+2][y+1]=1;
								return 1;
							}
						}
						if(Square[x+2][y].edge[3]->ismove==1)
						{
							if(Square[x+3][y].degree==3||Square[x+3][y].degree==4)
							{
								Searched[x][y]=1;
								Searched[x+1][y]=1;
								Searched[x+2][y]=1;
								Searched[x+3][y]=1;
								return 1;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}




int Count_AntDoublecorse()    //查找反双交的个数
{
	int i,j,num=0;
	
	memset(Searched,0,sizeof(Searched));
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=5;j++)
		{
			if(Searched[i][j]) continue;										//说明已经查找过了
			if((SingleChain(i,j))) {num++;	continue;}					//SingleChain 单链必为反双交
			if(DoubleChain(i,j)) {num++;continue;}						//DoubleChain 双链可能成为反双交
			if(Triple_Freedom(i,j)) {num++;continue;}					//Triple_freedem 某三自由度带来交叉的可能为反双交	
		}
	}
	return num ;
}


int Evaluation (int Turn)												//评估函数，评估某步棋下过之后的局面
{
	int Value = 0;	
	int Num_Antdoublecorse = 0;
	Turn=!Turn;
	if(Turn==myturn)
	{
		Num_Antdoublecorse = Count_AntDoublecorse();
		if(!IsDeadGridEdge())
		{
			if(Num_Antdoublecorse % 2 == 0)
			{
				Value = Value + 20;
			}
			else 
			{
				Value = Value - 20;
			}
		}
		else
		{
			if(Num_Antdoublecorse % 2 == 0)
			{
				Value = Value + 50;
			}
			else 
			{
				Value = Value - 50;
			}
		}
	}

	if(Turn != myturn)
	{
		Num_Antdoublecorse = Count_AntDoublecorse();
		if(!IsDeadGridEdge())
		{
			if(Num_Antdoublecorse % 2 == 1)
			{
				Value = Value + 20;
			}
			else
			{
				Value = Value - 20;
			}
		}
		else
		{
			if(Num_Antdoublecorse % 2 == 1)
			{
				Value = Value + 50;
			}
			else 
			{
				Value = Value - 50;
			}
		}
	}
	return Value;
}
