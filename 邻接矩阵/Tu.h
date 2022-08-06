#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

#define MAX_INT 2147483647

typedef char VerTexTyper;
typedef int ArcType;

typedef struct {
	int vex_count, arc_count;
	VerTexTyper* vexs;
	ArcType** arcs;
}AMGraph;

/*初始化*/
AMGraph* init_Graph();

/*查询图中元素，成功返回下标，失败返回-1*/
int search_elem(AMGraph* G, VerTexTyper v2);

/*打印邻接矩阵*/
void print_AMG(AMGraph* G);