#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

#define MAX_INT -1
#define MAX_TEMP_QUEUE 50

typedef char VerTexTyper;
typedef int ArcType;

typedef struct {
	int vex_count, arc_count;
	VerTexTyper* vexs;
	ArcType** arcs;
}AMGraph;

/*初始化*/
AMGraph* init_Graph(int vex_count, int arc_count);

/*创建图*/
bool creat_Graph(AMGraph** G);

/*查询图中元素，成功返回下标，失败返回-1*/
int search_elem(AMGraph* G, VerTexTyper v2);

/*打印邻接矩阵*/
void print_AMG(AMGraph* G);

/*DFS*/
void DFS(AMGraph* G, int index_v, bool* visited);

/*建立并初始化，访问表*/
bool* creat_and_init_visited(AMGraph* G);

/*释放图*/
void free_Graph(AMGraph* G);

/*释放访问表*/
 void free_visited(bool* visited);

 /*BFS*/
 void BFS(AMGraph* G,int i_v);

 /*创建队列并初始化*/
 int* creat_and_init_queue(AMGraph* G);

 /*队列循环自增*/
 void up_queue(int* up_num, int max);

 /*Prim算法构造最小生成树*/
 AMGraph* MST_Prim(AMGraph* G, int i_v);

 /*复制结点数据*/
 void copy_node(AMGraph* from, int i_from, AMGraph* to, int i_to);

 /*构造边结点*/
 void creat_ARC(AMGraph* G, int i_from, int i_to, int weight);