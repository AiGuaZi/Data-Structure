#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

#define ERROR -1			//返回错误
#define ENOMEM_ERROR -18	//无内存

#define YO_TU  1			//有向图
#define NO_TU -1			//无向图

#define ROAD_ERROR 0		//无路可走

#define MAX_INT 0x7FFFFFFF

typedef char VerTexType;

//边表结点
typedef struct ArcNode {
	int index_in_AdjList;    //存储在顶点表中的下表
	int info;                //存储边的信息，如：权值
	ArcNode* next;           //指向下一条边
}ArcNode;

//顶点表结点
typedef struct AdjList {
	VerTexType date;         //图结点数据
	ArcNode* head;           //邻接表头指针
}AdjList;

//图
typedef struct ALGraph {
	AdjList* AG;             //顶点表
	int vex_count, arc_count;//结点个数和边数
}ALGraph;

//存储结点到达aim_j结点的最短距离
typedef struct AimI_info {
	int aim_j;				//目标结点下标
	int info;
}AimI_info;

//Dijk算法辅助表
typedef struct Dijk_List {
	int** date;				//边界点值
	AimI_info* Aim;			//结点信息
}Dijk_List;

//辅助栈
typedef struct Stack {
	int* date;
	int top;
}Stack;



/*初始化图*/
ALGraph* init_Graph(int vex_count, int arc_count);

/*创建无向图*/
void creat_ALGraph(ALGraph*G,const int modle);

/*查询结点在顶点表中的下标*/
int search_node(const ALGraph* G,const VerTexType date);

/*打印无向图数据*/
void print_date(const ALGraph* G);

/*计算某结点*/
int cal_node_count(const AdjList* AG);

/*建立访问表*/
bool* creat_and_init_visited(ALGraph* G);

/*DFS*/
void DFS(ALGraph* G, int index_v,bool*visited);

/*释放图*/
void free_ALGraph(ALGraph* G);

/*释放一个边结点*/
void free_ArcNode(ArcNode* arc);

/*释放边表*/
void free_Arc(ArcNode* head);

/*释放访问表*/
void free_visited(bool* visited);

/*BFS*/
void BFS(ALGraph* G, int i_v);

/*队列指针自增函数*/
void up_queue(int* up_num, int max);

/*MST*/
ALGraph* MST_Prim(ALGraph* G, int i_v);

/*构造边结点*/
void creat_ARC(ALGraph* from, int i_from, ALGraph* to, int i_to, int info);

/*最短路劲——Dijkstra算法*/
int Dijkstra(ALGraph* G, int orign, int finish);

/*初始化Dijk辅助表*/
Dijk_List* init_DijkList(ALGraph* G);

/*打印Dijk辅助表*/
void print_DijkList(Dijk_List* D_List,int count);

/*判断某结点是否是一以知结点的前驱结点*/
bool is_PreNode(ALGraph* G, int is_i, int aim_i,int *info);

/*释放D_List辅助表*/
void free_D_List(Dijk_List* D_List,int vex_count);

/*拓扑排序*/
void Topo_Sort(ALGraph* G);

/*初始化栈*/
void init_Stack(int count, Stack**S);

/*判断有无前驱*/
bool YoNo_PreNode(ALGraph* G, int i_v);

/*搜索无前驱结点*/
void search_no_PreNode(ALGraph* G, Stack** no_PreNode);

/*删除图结点和其出度边*/
bool delete_Node(ALGraph* G, int i_v);