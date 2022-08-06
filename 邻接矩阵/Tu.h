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

/*��ʼ��*/
AMGraph* init_Graph();

/*��ѯͼ��Ԫ�أ��ɹ������±꣬ʧ�ܷ���-1*/
int search_elem(AMGraph* G, VerTexTyper v2);

/*��ӡ�ڽӾ���*/
void print_AMG(AMGraph* G);