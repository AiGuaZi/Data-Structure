#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

#define ERROR -1			//���ش���
#define ENOMEM_ERROR -18	//���ڴ�

#define YO_TU  1			//����ͼ
#define NO_TU -1			//����ͼ

#define ROAD_ERROR 0		//��·����

#define MAX_INT 0x7FFFFFFF

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

//�洢��㵽��aim_j������̾���
typedef struct AimI_info {
	int aim_j;				//Ŀ�����±�
	int info;
}AimI_info;

//Dijk�㷨������
typedef struct Dijk_List {
	int** date;				//�߽��ֵ
	AimI_info* Aim;			//�����Ϣ
}Dijk_List;

//����ջ
typedef struct Stack {
	int* date;
	int top;
}Stack;



/*��ʼ��ͼ*/
ALGraph* init_Graph(int vex_count, int arc_count);

/*��������ͼ*/
void creat_ALGraph(ALGraph*G,const int modle);

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

/*����ָ����������*/
void up_queue(int* up_num, int max);

/*MST*/
ALGraph* MST_Prim(ALGraph* G, int i_v);

/*����߽��*/
void creat_ARC(ALGraph* from, int i_from, ALGraph* to, int i_to, int info);

/*���·������Dijkstra�㷨*/
int Dijkstra(ALGraph* G, int orign, int finish);

/*��ʼ��Dijk������*/
Dijk_List* init_DijkList(ALGraph* G);

/*��ӡDijk������*/
void print_DijkList(Dijk_List* D_List,int count);

/*�ж�ĳ����Ƿ���һ��֪����ǰ�����*/
bool is_PreNode(ALGraph* G, int is_i, int aim_i,int *info);

/*�ͷ�D_List������*/
void free_D_List(Dijk_List* D_List,int vex_count);

/*��������*/
void Topo_Sort(ALGraph* G);

/*��ʼ��ջ*/
void init_Stack(int count, Stack**S);

/*�ж�����ǰ��*/
bool YoNo_PreNode(ALGraph* G, int i_v);

/*������ǰ�����*/
void search_no_PreNode(ALGraph* G, Stack** no_PreNode);

/*ɾ��ͼ��������ȱ�*/
bool delete_Node(ALGraph* G, int i_v);