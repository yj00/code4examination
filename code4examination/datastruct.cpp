#include"pch.h"
#include"datastruct.h"

//��ʼ��ջ
Status InitStack(SqStack&s) {
	s.base = NULL;
	s.top = NULL;
	s.base = (ElemType*)malloc(Stack_Init_Size * sizeof(ElemType));
	if (!s.base)exit(flow);
	s.top = s.base;
	s.stacksize = Stack_Init_Size;
	return ok;
}

//��ȡջ������
Status GetTop(const SqStack &s, ElemType& e) {
	if (s.top == s.base) return error;
	e = *(s.top - 1);
	return ok;
}


//ѹջ
Status Push(SqStack &s, ElemType &e) {
	int length = s.top - s.base;
	if (s.stacksize == length) {
		s.base = (ElemType*)realloc(s.base, (Stack_ADD + s.stacksize) * sizeof(ElemType));
		s.top = s.base + s.stacksize;
		s.stacksize = s.stacksize + Stack_ADD;
		if (!s.base)exit(flow);
	}
	*s.top = e;
	s.top++;
	return ok;
}