#pragma once
#include<iostream>
#include<stdlib.h>

#define NO_MEMORY 18
#define ERROR -1

using namespace std;

//ͼ��� �洢��������
typedef char VerTexType;

//�߽��
typedef struct ArcNode {
	int index_tail;                 //�洢��β
	int index_head;                 //�洢��ͷ
	int info;                       //�洢����Ϣ����:Ȩֵ
	ArcNode* next_in ;              //�����һ���
	ArcNode* next_out;              //������һ���
}ArcNode;

//������
typedef struct AdjList {
	VerTexType date;                //���洢��Ϣ
	ArcNode* head_in;               //���ͷ���
	ArcNode* head_out;              //����ͷ���
};

//����ͼ
typedef struct AGraph {
	AdjList* AG;                    //�����
	int vex_count, arc_count;       //�������ͱ���
}AGraph;


/*��������ͼ*/
AGraph* creat_AGraph();

/*����һ����*/
void creat_Arc(AGraph* G);

/*���ҽ���ڶ�����е�λ��*/
int search_node(AGraph* G, VerTexType v);

/*��ӡ��Ϣ*/
void print_info(AGraph* G);

/*DFS*/
void DFS(AGraph* G, int index_v, bool* visited);

/*�������ʱ�*/
bool* creat_visited(AGraph* G);