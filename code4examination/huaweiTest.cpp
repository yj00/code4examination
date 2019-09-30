#include"pch.h"
#include<iostream>
#include<vector>
#include<string>
#include<sstream>


using namespace std;


//提取字符串中的数
vector<int> findNumInString(string str, vector<int> numArr, int startIndex, int endIndex) {
	int i;
	if (startIndex >= endIndex) {
		return numArr;
	}
	else {
		string strnum;
		for (i = startIndex; i < endIndex; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				strnum = strnum + str[i];
				if (str[i + 1] < '0' || str[i + 1] > '9') {
					stringstream ss; ss << strnum;
					int num; ss >> num;
					numArr.push_back(num);
					strnum = "";
				}
			}
		}
		return numArr;
	}
}

//判断距离
void distanceJudging(vector<int> A, vector<int>B, vector<int> R) {
	int i, j;
	for (i = 0; i < A.size(); i++) {
		//std::cout<< A[i] << endl;
		int min = INT_MAX;
		int indexA = INT_MIN;
		for (j = 0; j < B.size(); j++) {
			if (A[i] <= B[j]) {
				//indexA = 0;
				int x = B[j] - A[i];
				if (x >= 0 && x <= R[0]) {
					cout << "(" << A[i] << "," << B[j] << ")";
					indexA = 1;
				}
				else {
					if (min > x) {
						min = x;
					}
				}
			}
		}
		if (min > R[0] && indexA == INT_MIN) {
			cout << "(" << A[i] << "," << A[i] + min << ")";
		}
	}
}


