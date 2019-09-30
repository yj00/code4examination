#include"pch.h"
#include<malloc.h>
#include<iostream>
#include<ctype.h>

typedef bool Status;
typedef char ElemType;
typedef struct NodeType {
	ElemType data;
	NodeType *next;
}NodeType,*LinkType;//节点类型，指针类型

typedef struct {
	LinkType head, tail;
	int size;
}OrderdList;//有序链表类型

typedef OrderdList OrderedSet;
OrderedSet Set1, Set2, Set3;//必须要把三个集合声明为全局变量，因为这样才能保存CreatSetd对其的更改。使其在所有函数中都有效

