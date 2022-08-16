#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

#define NO_MEMORY -18
#define ERROR -1

typedef char VerTexType;

//�߽��
typedef struct ArcNode {
	bool mark;
	int in_vex;
	ArcNode* in_next;
	int out_vex;
	ArcNode* out_next;
	int info;
}ArcNode;

//������
typedef struct AdjList {
	VerTexType date;
	ArcNode* head;
}AdjList;

//ͼ
typedef struct AGraph {
	AdjList* AG;
	int vex_count, arc_count;
}AGraph;

/*����ͼ*/
AGraph* creat_AGraph();

/*�����߽��*/
bool creat_ArcNode(const AGraph* G);

/*����Ŀ�����ڶ�����е�λ�ã��������±�*/
int search_node(const AGraph* G, VerTexType elem);

/*��ӡ�����ָ���������ӵ���Ϣ*/
void print_info(const AGraph* G);