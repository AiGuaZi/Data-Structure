#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

#define ERROR -1
#define ENOMEM_ERROR -18

#define YO_TU  1
#define NO_TU -1

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

/*创建无向图*/
ALGraph* creat_ALGraph(const int modle);

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

void up_queue(int* up_num, int max);