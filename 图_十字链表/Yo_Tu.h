#pragma once
#include<iostream>
#include<stdlib.h>

#define NO_MEMORY 18
#define ERROR -1

using namespace std;

//图结点 存储数据类型
typedef char VerTexType;

//边结点
typedef struct ArcNode {
	int index_tail;                 //存储弧尾
	int index_head;                 //存储弧头
	int info;                       //存储边信息，如:权值
	ArcNode* next_in ;              //入度下一结点
	ArcNode* next_out;              //出度下一结点
}ArcNode;

//顶点结点
typedef struct AdjList {
	VerTexType date;                //结点存储信息
	ArcNode* head_in;               //入度头结点
	ArcNode* head_out;              //出度头结点
};

//建立图
typedef struct AGraph {
	AdjList* AG;                    //顶点表
	int vex_count, arc_count;       //结点个数和边数
}AGraph;


/*建立有向图*/
AGraph* creat_AGraph();

/*构造一条边*/
void creat_Arc(AGraph* G);

/*查找结点在顶点表中的位置*/
int search_node(AGraph* G, VerTexType v);

/*打印信息*/
void print_info(AGraph* G);

/*DFS*/
void DFS(AGraph* G, int index_v, bool* visited);

/*创建访问表*/
bool* creat_visited(AGraph* G);