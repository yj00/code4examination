﻿/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。
*/
#include"pch.h"
#include<cstdio>
#include<iostream>
#include<vector>

#define max(a,b)(a>b ? a:b);
#define min(a,b)(a<b ? a:b);

using namespace std;

double findMedianSortArrays(vector<int> &nums1, vector<int> &nums2) {
	int m = nums1.size();
	int n = nums2.size();
	if (m > n) {
		return findMedianSortArrays(nums2, nums2);
	}
	int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
	while (iMin < iMax) {
		int i = (iMin + iMax) / 2;
		int j = halfLen - i;
		if (i < iMax && nums2[j - 1]>nums1[i]) {
			iMin = i + 1;
		}
		else if(i>iMin && nums1[i-1]>nums2[j]) {
			iMax = i - 1;
		}
		else {
			int maxLeft = 0;
			if (i == 0) { maxLeft = nums2[j - 1]; }
			else if(j==0) {
				maxLeft = nums1[i - 1];
			}
			else {
				maxLeft = max(nums1[i - 1], nums2[j - 1]);
			}
			if ((m + n) % 2 == 1) {
				return maxLeft;
			}
			int minRight = 0;
			if (i == m) {
				minRight = nums2[j];
			}
			else if (j == n) {
				minRight = nums1[i];
			}
			else {
				minRight = min(nums2[j], nums1[i]);
			}
			return (maxLeft + minRight) / 2.0;
		}
	}

}
