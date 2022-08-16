#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

#define NO_MEMORY -18
#define ERROR -1

typedef char VerTexType;

//边结点
typedef struct ArcNode {
	bool mark;
	int in_vex;
	ArcNode* in_next;
	int out_vex;
	ArcNode* out_next;
	int info;
}ArcNode;

//顶点结点
typedef struct AdjList {
	VerTexType date;
	ArcNode* head;
}AdjList;

//图
typedef struct AGraph {
	AdjList* AG;
	int vex_count, arc_count;
}AGraph;

/*建立图*/
AGraph* creat_AGraph();

/*建立边结点*/
bool creat_ArcNode(const AGraph* G);

/*搜索目标结点在顶点表中的位置，返回其下标*/
int search_node(const AGraph* G, VerTexType elem);

/*打印顶点表，指针域所连接的信息*/
void print_info(const AGraph* G);