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

/*��ʼ��*/
AMGraph* init_Graph(int vex_count, int arc_count);

/*����ͼ*/
bool creat_Graph(AMGraph** G);

/*��ѯͼ��Ԫ�أ��ɹ������±꣬ʧ�ܷ���-1*/
int search_elem(AMGraph* G, VerTexTyper v2);

/*��ӡ�ڽӾ���*/
void print_AMG(AMGraph* G);

/*DFS*/
void DFS(AMGraph* G, int index_v, bool* visited);

/*��������ʼ�������ʱ�*/
bool* creat_and_init_visited(AMGraph* G);

/*�ͷ�ͼ*/
void free_Graph(AMGraph* G);

/*�ͷŷ��ʱ�*/
 void free_visited(bool* visited);

 /*BFS*/
 void BFS(AMGraph* G,int i_v);

 /*�������в���ʼ��*/
 int* creat_and_init_queue(AMGraph* G);

 /*����ѭ������*/
 void up_queue(int* up_num, int max);

 /*Prim�㷨������С������*/
 AMGraph* MST_Prim(AMGraph* G, int i_v);

 /*���ƽ������*/
 void copy_node(AMGraph* from, int i_from, AMGraph* to, int i_to);

 /*����߽��*/
 void creat_ARC(AMGraph* G, int i_from, int i_to, int weight);