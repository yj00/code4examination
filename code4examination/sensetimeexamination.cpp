#include "pch.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>


//ตÝน้
int fn(int n, int a, int b, int c, int f0) {
	int fout;
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		return f0;
	}
	if (n > 0) {
		return a * fn(n - 1, a, b, c, f0) + b * fn(n - 2, a, b, c, f0) + c * fn(n - 3, a, b, c, f0) + 2 * n*n - n + 32767;
	}
}

//
void mellonW(int *mellon_t, int *mellon_w, int *mellon_m, int *maxW, int n, int m) {
	//int maxW = 0;
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (mellon_t[i] >= mellon_m[j] && mellon_w[i] > maxW[j])
				maxW[j] = mellon_w[i];
		}
	}
}