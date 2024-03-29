/*排序算法的实现*/
#include "pch.h"
#include<iostream>
#include<stack>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define swap(x,y){int temp=x;x=y;y=temp;}

int getMid(int *a, int left, int mid, int right);
int leftrightquickSort(int *a, int left, int right);
int curprevquickSort(int *a, int left, int right);
int wkquickSort(int *a, int left, int right);

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


//6.Quick Sort:时间复杂度O(nlog2(n))，空间复杂度O(1),In-place 不稳定
void quickSort(int *a, int left,int right) {
	if (left > right) {
		return;
	}
/*	if ((right - left) + 1 < 10) {
		insertSort(a + left, right - left + 1);
	}
*/	//int div = leftrightquickSort(a, left, right);
	int div = wkquickSort(a, left, right);
	//int div = curprevquickSort(a, left, right);
	quickSort(a, left, div - 1);
	quickSort(a, div + 1, right);
}
//
int getMid(int *a, int left, int mid, int right) {
	if (a[left] > a[mid]) {
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] > a[right]) {
			return right;
		}
		else { return left; };
	}
	else {
		if (a[mid] < a[right]) {
			return mid;
		}else if(a[right]>a[left]){
			return right;
		}
		else {
			return left;
		}
	}
}
//左右指针法
int leftrightquickSort(int *a, int left, int right) {
/*	int mid = left + ((right - left) + 1) >> 1;
	mid = getMid(a, left, mid, right);
	if (mid != right)
		swap(a[mid], a[right]);
*/	int key = right;
	int start = left, end = right;
	while (start < end) {
		while (start < end&&a[start] <= a[key]) {
			++start;
		}
		while (start<end&&a[end]>=a[key]) {
			--end;
		}
		swap(a[start], a[end]);
	}
	swap(a[start], a[key]);
	return start;
}
//挖坑法
int wkquickSort(int *a, int left, int right) {
/*	int mid = left + ((right - left) + 1) >> 1;
	mid = getMid(a, left, mid, right);
	if (mid != right)
		swap(a[mid], a[right]);
*/	int key = a[right];
	while (left < right) {
		while (left < right&&a[left]<=key) {
			++left;
		}
		a[right] = a[left];
		while (left < right &&a[right] >= key) {
			--right;
		}
		a[left] = a[right];
	}
	a[left] = key;
	return left;
}
//前后指针
int curprevquickSort(int *a, int left,int right) {
/*	int mid = left + ((right - left) + 1) >> 1;
	mid = getMid(a, left, mid, right);
	if (mid != right)
		swap(a[mid], a[right]);
*/	int cur = left;
	int prev = left - 1;
	int key = a[right];
	while (cur < right) {
		if (a[cur] < key && ++prev != cur) {
			swap(a[cur], a[prev]);
		}
		++cur;
	}
	swap(a[++prev], a[right]);
	return prev;
}

void quickSortNOR(int *a, int left, int right) {
	std::stack<int> s;
	if (left < right) {
		s.push(left);
		s.push(right);
	}
	while (!s.empty()) {
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();
		int div = leftrightquickSort(a, left, right);
		//if ((right - left + 1) < 20) {
		//	insertSort(a + left, right - left + 1);
		//}
		//else
		if (left < div - 1) {
			s.push(left);
			s.push(div - 1);
		}
		if (div + 1 < right) {
			s.push(div + 1);
			s.push(right);
		}
	}
}

//7.Heap Sort:时间复杂度O(nlog(n))堆排序一般采用大根堆，较快排稳定，无需额外的空间存储代价，In-place,不稳定
void heapSort(int *a, int n) {
	
	//数组实现堆
	int i = n / 2 - 1;
	int first = i, last = n - 1;
	while (i >= 0) {
		int curIndex = first * 2 + 1;
		while (curIndex <= last) {
			if (curIndex <= last && a[curIndex] < a[curIndex + 1]) {
				curIndex++;
			}
			if (a[first] < a[curIndex]) {
				swap(a[first], a[curIndex]);
				first = curIndex;
				curIndex = first * 2 + 1;
			}
			else
				break;
		}
		i--;
	}
	first = 0;
	while (first <= last) {
		swap(a[first], a[last]);
		last--;
		int curIndex = first * 2 + 1;
		while (curIndex <= last) {
			if (curIndex <= last && a[curIndex] < a[curIndex + 1]) {
				curIndex++;
			}
			if (a[first] < a[curIndex]) {
				swap(a[first], a[curIndex]);
				first = curIndex;
				curIndex = first * 2 + 1;
			}
			else
				break;
		}
	}
}
/*
class HeapSort {
public:
	void AdjustDown(int *A, int root, int n) {
		int parent = root;
		int child = parent * 2 + 1;
		while (child < n) {
			if ((child + 1) < n&&A[child + 1] > A[child]) {
				++child;
			}
			if (A[child] > A[parent]) {
				swap(A[parent], A[child]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
				break;
		}
	}
	int* heapSort(int*A, int n) {
		for (int i = (n - 2) / 2; i >= 0; i--) {
			AdjustDown(A, i, n);
		}
		int end = n - 1;
		while (end > 0) {
			swap(A[0], A[end]);
			AdjustDown(A, 0, end);
			end--;
		}
		return A;
	}
};
*/
//8.计数排序:时间复杂度O(n+k),空间复杂度O(k),Out-place,稳定
void countSort(int *a, int n) {
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++) {
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	vector<int> counts(max - min + 1);
	for (int i = 0; i < n; i++) {
		counts[a[i] - min]++;
	}
	int index = 0;
	for (int j = 0; j < counts.size(); j++) {
		int n = counts[j];
		while (n--) {
			a[index] = j + min;
			index++;
		}
	}
}


//9.桶排序:时间复杂度O(n+k),空间复杂度O(n+k),Out-place,稳定
void bucketSort(int *a, int n, int bucketCount) {
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++) {
		if (min > a[i])
			min = a[i];
		if (max < a[i])
			max = a[i];
	}
	vector<vector<int>> buckets(bucketCount);
	int bucketSize = ceil((double)(max - min + 1) / bucketCount);
	for (int i = 0; i < n; i++) {
		int bucketIndex = (a[i] - min) / bucketSize;
		buckets[bucketIndex].push_back(a[i]);
	}
	int index = 0;
	for (vector<int> bucket : buckets) {
		if (!bucket.empty()) {
			for (int i = 1; i < bucket.size(); i++) {
			
	for (int j = i - 1; j >= 0 && bucket[j + 1] < bucket[j]; j--) {
					swap(bucket[j + 1], bucket[j]);
				}
			}
			for (int value : bucket) {
				a[index] = value;
				index++;
			}
		}
	}

}

//10.Radix Sort:时间复杂度O(n+k),空间复杂度O(n+k)，Out-place, 稳定
void radixSort(int *a, int n,int dec,int order) {
	int i, j;
	int index;
	int num[10];


	int curdigit = 10;
	bool isOverHighest = false;
	while (!isOverHighest) {
	}
}















