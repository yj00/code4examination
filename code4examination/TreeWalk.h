#pragma once
#include<iostream>
#define N 7

using namespace std;

class TreeWalk
{
public:
	int data;
	TreeWalk *leftChild;//ָ��
	TreeWalk *rightChild;
};
typedef TreeWalk *Btree;

