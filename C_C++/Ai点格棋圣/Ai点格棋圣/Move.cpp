
#include "Move.h"


int move(LIST *Movelist)
{
	
	int i;
	int j;
	int len=0;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			//搜索没下过的竖边
			if(i!=5)
			{
			
				if(Vertical[i][j].ismove==1)
				{
					if(Square[i+1][j].degree==2||Square[i+1][j+1].degree==2)
					{
						//free++;
					}
					else
					{
						Movelist[len].move_type=1;
						Movelist[len].move_hor=i;
						Movelist[len].move_ver=j;
						len++;
					}
				}
			}
			//搜索没下过的横边
			if(j!=5)
			{
				if(Horizon[i][j].ismove==1)
				{
					if(Square[i][j+1].degree==2||Square[i+1][j+1].degree==2)
					{
						//free++;
					}
					else
					{
						Movelist[len].move_type=0;
						Movelist[len].move_hor=i;
						Movelist[len].move_ver=j;
						len++;
					}
				}
			}
		}
	}
	return len;
}
