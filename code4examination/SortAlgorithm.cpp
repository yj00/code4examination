/*排序算法的实现*/
#include "pch.h"
#include<cstdio>
#include<cstring>


#define swap(x,y){int temp=x;x=y;y=temp;}

//1.Select Sort:时间复杂度O(n^2) 空间复杂度O(1),In-place,不稳定
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



//2.Bubble Sort:时间复杂度O(n^2)，空间复杂度O(1)，In-place,稳定
void bubbleSort(int *a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if(a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}


//3.Insert Sort:时间复杂度O(n^2)，空间复杂度O(1),In-place,稳定
void insertSort(int *a, int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--) {
			swap(a[j + 1], a[j]);		
		}
	}
/*	for (size_t i = 1; i < n; ++i)//用end的位置控制边界
	{
		//单趟排序
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0&&a[end] > tmp)//循环继续条件
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
*/
}

//4.Shell Sort:时间复杂度O(nlog2n)，空间复杂度O(1),In-place,不稳定
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


//5.Merge Sort:时间复杂度 O(n*log2(n)),外加O(n)空间复杂度，Out-place 稳定
void __MergeSort(int *a, int left, int right, int *tmp) {
	if (left >= right)
		return;
/*	if (right - left + 1 < 10) {
		insertSort(a + left, right - left + 1);
	}
*/	int mid = left + ((right - left) >> 1);	
	__MergeSort(a, left, mid, tmp);//归并左边的数组
	__MergeSort(a, mid + 1, right, tmp);//归并右边的数组
	//将排好序的两部分数组归并
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


//6.Quick Sort:时间复杂度O(nlog2(n))，空间复杂度O(log2(n)),In-place 不稳定




//7.Heap Sort:时间复杂度O(nlog(n))堆排序一般采用大根堆，较快排稳定，无需额外的空间存储代价，In-place,不稳定


//8.计算排序:时间复杂度O(n+k),空间复杂度O(k),Out-place,稳定



//9.桶排序:时间复杂度O(n+k),空间复杂度O(n+k),Out-place,稳定


//10.Radix Sort:时间复杂度O(n+k),空间复杂度O(n+k)，Out-place, 稳定
















