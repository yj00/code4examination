#include"pch.h"
#include<stdlib.h>
#include<stdio.h>

int a[1000][1000];
int d[1000];
int p[1000];
int i, j, k;
int m, n;

void djsltra() {
	int min1;
	int x, y, z;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = z;
		a[y][x] = z;
	}
	for (i = 1; i <= n; i++) {
		d[i] = INT_MAX;
	}
	d[1] = 0;
	for (i = 1; i <= n; i++) {
		min1 = INT_MAX;
		//�������forѭ���Ĺ�������ð������Ŀ�����ҵ�δ���ʽڵ���d[j]ֵ��С���Ǹ��ڵ㣬
		//��Ϊ��һ�����ʽڵ㣬��k���
		for (j = 1; j <= n; j++)
			if (!p[j] && d[j] < min1)
			{
				min1 = d[j];
				k = j;
			}
		//p[k]=d[k]; // ����ԭ���Ĵ��룬����һ �������������ʼʱ��ִ�е�����k=1����d[1]=0
	   //�Ӷ�p[1]����0�������Ļ��������ѭ����֮���ÿ��ִ��֮��k���ǵ���1��
		p[k] = 1; //��1��ʾ��k���ڵ��Ѿ����ʹ���
		for (j = 1; j <= n; j++)
			if (a[k][j] != 0 && !p[j] && d[j] > d[k] + a[k][j])
				d[j] = d[k] + a[k][j];
	}
	//���������Դ�ڵ㵽����ÿ���ڵ����С����
	for (i = 1; i < n; i++)
		printf("%d->", d[i]);
	printf("%d\n", d[n]);
}