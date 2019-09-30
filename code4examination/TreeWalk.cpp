#include "pch.h"
#include "TreeWalk.h"
#include<iostream>

using namespace std;

TreeWalk *createNode(int value) {
	TreeWalk*q = new TreeWalk;
	q->leftChild = nullptr;
	q->rightChild = nullptr;
	q->data = value;
	return q;
}


Btree createBiTree(int *arr,int n)
{
	TreeWalk *p[N] = { NULL };
	//int array[6] = { 6,5,7,2,5,8 };//ÊäÈëµÄ¶ş²æÊ÷
	for (int i = 0; i < n; ++i)
		p[i] = createNode(arr[i]);
	for (int i = 0; i < n / 2; i++)
	{
		p[i]->leftChild = p[i * 2 + 1];
		p[i]->rightChild = p[i * 2 + 2];
	}
	return p[0];
}

int visit(Btree tree) {
	return tree->data;
}

void preorderTree(Btree tree) {
	if (tree) {
		cout << visit(tree) << " ";
		preorderTree(tree->leftChild);
		preorderTree(tree->rightChild);
	}
}

void inorderTree(Btree tree) {
	if (tree) {
		preorderTree(tree->leftChild);
		cout << visit(tree) << " ";		
		preorderTree(tree->rightChild);
	}
}

void inorderTree(Btree tree) {
	if (tree) {
		preorderTree(tree->leftChild);		
		preorderTree(tree->rightChild);
		cout << visit(tree) << " ";
	}
}
