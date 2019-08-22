/*�����㷨��ʵ��*/
#include "pch.h"
#include<cstdio>
#include<cstring>


#define swap(x,y){int temp=x;x=y;y=temp;}

//1.Select Sort:ʱ�临�Ӷ�O(n^2) �ռ临�Ӷ�O(1),In-place,���ȶ�
void selectSort(int *a, int n) {
	for (int i = 0; i < n; i++) {
		int minN = i;
		for (int j = i + 1; j < n; j++) {
			if (a[minN] > a[j]) {
				minN = j;
			}		
		}
		swap(a[minN], a[i]);
	}
}



//2.Bubble Sort:ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)��In-place,�ȶ�
void bubbleSort(int *a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if(a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}


//3.Insert Sort:ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1),In-place,�ȶ�
void insertSort(int *a, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--) {
			swap(a[j + 1], a[j]);		
		}
	}
/*	for (size_t i = 1; i < n; ++i)//��end��λ�ÿ��Ʊ߽�
	{
		//��������
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0&&a[end] > tmp)//ѭ����������
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
*/
}

//4.Shell Sort:ʱ�临�Ӷ�O(nlog2n)���ռ临�Ӷ�O(1),In-place,���ȶ�
void shellSort(int *a, int n) {
	int d = n / 2;
	while (d >= 1) {
/*		for (int i = d; i < n; i++) {
			int j = i - d;
			int tmp = a[i];
			while (j >= 0 && a[j] > tmp) {
				a[j + d] = a[j];
					j -= d;
			}
			a[j + d] = tmp;
		}
*/		for (int i = d; i < n; i++) {
			for (int j = i - d; j >= 0 && a[j + d] < a[j]; j--) {
				swap(a[j + d], a[j]);
			}
		}
		d = d / 2;
	}
}


//5.Merge Sort:ʱ�临�Ӷ� O(n*log2(n)),���O(n)�ռ临�Ӷȣ�Out-place �ȶ�
void __MergeSort(int *a, int left, int right, int *tmp) {
	if (left >= right)
		return;
/*	if (right - left + 1 < 10) {
		insertSort(a + left, right - left + 1);
	}
*/	int mid = left + ((right - left) >> 1);	
	__MergeSort(a, left, mid, tmp);//�鲢��ߵ�����
	__MergeSort(a, mid + 1, right, tmp);//�鲢�ұߵ�����
	//���ź��������������鲢
	int leftstart = left, leftend = mid;
	int rightstart = mid + 1, rightend = right;
	int index = left;
	while (leftstart <= leftend && rightstart <= rightend)
	{
		if (a[leftstart] <= a[rightstart]) {
			tmp[index++] = a[leftstart++];
		}
		else {
			tmp[index++] = a[rightstart++];
		}
	}
	while (leftstart <= leftend) {
		tmp[index++] = a[leftstart++];
	}
	while (rightstart <= rightend) {
		tmp[index++] = a[rightstart++];
	}
	index = left;
	while (index <= right) {
		a[index] = tmp[index];
		++index;
	}
}


//6.Quick Sort:ʱ�临�Ӷ�O(nlog2(n))���ռ临�Ӷ�O(log2(n)),In-place ���ȶ�




//7.Heap Sort:ʱ�临�Ӷ�O(nlog(n))������һ����ô���ѣ��Ͽ����ȶ����������Ŀռ�洢���ۣ�In-place,���ȶ�


//8.��������:ʱ�临�Ӷ�O(n+k),�ռ临�Ӷ�O(k),Out-place,�ȶ�



//9.Ͱ����:ʱ�临�Ӷ�O(n+k),�ռ临�Ӷ�O(n+k),Out-place,�ȶ�


//10.Radix Sort:ʱ�临�Ӷ�O(n+k),�ռ临�Ӷ�O(n+k)��Out-place, �ȶ�















