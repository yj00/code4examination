#include"pch.h"
#include<malloc.h>
#include<iostream>
#include<ctype.h>

typedef bool Status;
typedef char ElemType;
typedef struct NodeType {
	ElemType data;
	NodeType *next;
}NodeType,*LinkType;//�ڵ����ͣ�ָ������

typedef struct {
	LinkType head, tail;
	int size;
}OrderdList;//������������

typedef OrderdList OrderedSet;
OrderedSet Set1, Set2, Set3;//����Ҫ��������������Ϊȫ�ֱ�������Ϊ�������ܱ���CreatSetd����ĸ��ġ�ʹ�������к����ж���Ч

