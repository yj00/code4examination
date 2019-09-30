#pragma once
#include"pch.h"
#include<iostream>
#include<malloc.h>

using namespace std;

typedef int Status;
typedef char ElemType;


#define ok 1
#define error 0
#define Stack_Init_Size 10
#define Stack_ADD 10
#define flow 0

typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

//≥ı ºªØ
Status InitStack(SqStack &s);


