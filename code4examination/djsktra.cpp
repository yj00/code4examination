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
		//下面这个for循环的功能类似冒泡排序，目的是找到未访问节点中d[j]值最小的那个节点，
		//作为下一个访问节点，用k标记
		for (j = 1; j <= n; j++)
			if (!p[j] && d[j] < min1)
			{
				min1 = d[j];
				k = j;
			}
		//p[k]=d[k]; // 这是原来的代码，用下一 条代码替代。初始时，执行到这里k=1，而d[1]=0
	   //从而p[1]等于0，这样的话，上面的循环在之后的每次执行之后，k还是等于1。
		p[k] = 1; //置1表示第k个节点已经访问过了
		for (j = 1; j <= n; j++)
			if (a[k][j] != 0 && !p[j] && d[j] > d[k] + a[k][j])
				d[j] = d[k] + a[k][j];
	}
	//最终输出从源节点到其他每个节点的最小距离
	for (i = 1; i < n; i++)
		printf("%d->", d[i]);
	printf("%d\n", d[n]);
}