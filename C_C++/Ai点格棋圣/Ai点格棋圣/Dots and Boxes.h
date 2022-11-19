#ifndef    Dots_and_Boxes_h_
#define	   Dots_and_Boxes_h_



#include	<stdio.h>
#include	<string.h>
#include	<math.h>
#include	<stdlib.h>
#include	<conio.h> 
#include	<time.h> 


/*
*2021.11.3
*棋盘元素，点，游戏中所需要素的以及结构体
*/


#define Max_deep	8				//模糊搜的最大深度
#define Max_len		25				//精确搜的最大深度
//基本数据结构


//边的表示
typedef struct edge
{
	struct GRID *node[2];			//边要依附于两个点
	int length;						//边的长度 也用来之后计算链和环的长度
	int ismove;						//是否该边已移除0-移除，1-未移除
	struct edge *next;				//下一条边
	struct edge *pre;				//上一条边
}EDGE;

//格子表示
typedef struct GRID
{
	EDGE *NextEdge;
	struct GRID *NextNode;
	EDGE *edge[4];					//属于这个格子的四条边
	int x,y;						//该格子的位置坐标 坐标从0开始的
	int	degree;						//自由度
	int owner;						//占有者
	int ground;						//是否是真实的格子，1-是，0-不是

}NODE;


//走法
typedef struct list
{
	int move_type;					//边的类型（水平，竖直）
	int move_ver;					//竖直边编号
	int move_hor;					//水平边编号

}LIST;

extern NODE Square[7][7];			//格子数组，包含假想格子，ground=0
extern EDGE Horizon[6][6];			//水平边
extern EDGE Vertical[6][6];			//竖直边
extern int myturn;					//我方是先手还是后手，1代表先手，2代表后手
extern int Iscapture(int HorV,int x,int y,int turn);
extern int x,y;						//返回的边的位置
extern LIST Bestmove;				//最佳招法
extern int Search(int deep,int alpha,int beta,int turn);
extern bool IsDeadGridEdge();
extern int mboxes,yboxes;
//void Final_Occupy();


#endif

















