#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

#define ERROR -1
#define ENOMEM_ERROR -18

#define YO_TU  1
#define NO_TU -1

typedef char VerTexType;

//�߱���
typedef struct ArcNode {
	int index_in_AdjList;    //�洢�ڶ�����е��±�
	int info;                //�洢�ߵ���Ϣ���磺Ȩֵ
	ArcNode* next;           //ָ����һ����
}ArcNode;

//�������
typedef struct AdjList {
	VerTexType date;         //ͼ�������
	ArcNode* head;           //�ڽӱ�ͷָ��
}AdjList;

//ͼ
typedef struct ALGraph {
	AdjList* AG;             //�����
	int vex_count, arc_count;//�������ͱ���
}ALGraph;

/*��������ͼ*/
ALGraph* creat_ALGraph(const int modle);

/*��ѯ����ڶ�����е��±�*/
int search_node(const ALGraph* G,const VerTexType date);

/*��ӡ����ͼ����*/
void print_date(const ALGraph* G);

/*����ĳ���*/
int cal_node_count(const AdjList* AG);

/*�������ʱ�*/
bool* creat_and_init_visited(ALGraph* G);

/*DFS*/
void DFS(ALGraph* G, int index_v,bool*visited);

/*�ͷ�ͼ*/
void free_ALGraph(ALGraph* G);

/*�ͷ�һ���߽��*/
void free_ArcNode(ArcNode* arc);

/*�ͷű߱�*/
void free_Arc(ArcNode* head);

/*�ͷŷ��ʱ�*/
void free_visited(bool* visited);

/*BFS*/
void BFS(ALGraph* G, int i_v);

void up_queue(int* up_num, int max);