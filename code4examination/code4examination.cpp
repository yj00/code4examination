// code4examination.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int fn(int n, int a, int b, int c, int f0);
void mellonW(int *mellon_t, int *mellon_w, int *mellon_m, int *maxW, int n, int m);
void selectSort(int *a, int n);
void bubbleSort(int *a, int n);
void insertSort(int *a, int n);
void shellSort(int *a, int n);
void __MergeSort(int *a, int left, int right, int *tmp);
void quickSort(int *a, int left, int right);
void quickSortNOR(int *a, int left, int right);

int main()
{
/*
	int n, a, b, c, f0;
	int fout;
	scanf_s("%d %d %d %d %d", &n, &a, &b, &c, &f0);
	fn(n, a, b, c, f0);
	printf("%d\n", fn(n, a, b, c, f0));
*/
/*	
	
	int n, m;
	cin >> n >> m;
	cout << "输入" << n << "个西瓜参数(t w):" << endl;
	int mellon_t[1000], mellon_w[1000], mellon_m[100];
	int maxW[100] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf_s("%d%%d/n", &mellon_t[i], &mellon_w[i]);
		//cin >> mellon_t[i] >> mellon_w [i];
		//char ch = '\n';
		//cin >> ch;
	}
	cout << "输入" << m << "时间参数:" << endl;
	for (int i = 0; i < m; i++) {
		cin >> mellon_m[i];
	}
	mellonW(mellon_t, mellon_w, mellon_m, maxW, n, m);
	cout << "各时间段下最重的西瓜:" << endl;
	for (int i = 0; i < m; i++) {
		cout << maxW[i] << endl;
	}
*/	//Node mellon[n];
	int a[10] = {1,2,6,3,4,5,9,8,7,0};
	int n = 10;
	//selectSort(a, n);
	//bubbleSort(a, n);
	//insertSort(a, n);
	//shellSort(a, n);

	//int *tmp = (int*)malloc(10 * sizeof(int));
	//__MergeSort(a, 0, n-1, tmp);
	//free(tmp);

	//quickSort(a, 0, n - 1);
	quickSortNOR(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		std::cout << a[i];
	}
	std::cout << endl;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
