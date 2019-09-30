//对于一个具有树特征的无向图，我们可以选择任何一个节点作为根。
//图因此可以成为树，在所有可能的树中,具有最小高度的树称为最小高度树。
//给出这样的图，写出一个函数招到所有最小高度树并返回他们的根节点
/*本题给定条件是”树“特征无向图。对于这种图，我们有以下几个结论：（在邓俊辉教授的《数据结构习题集》6-9和6-10有详细证明）

1. 边数 = 顶点数 - 1（每引入一个新顶点只能引入一条新边，否则会出现环路）
2. 若称全图最长路径为直径，则直径（不一定唯一）的两个端点一定是两个叶子节点
3. 从任意节点出发的广度优先搜索最后一个节点一定是直径的端点
4. 若称全图与所有其他节点的最大距离最小的节点（注意！本题要找的是以哪个节点为根形成树高度最小，
与这个描述等价，所以这中节点其实就是本题欲寻找的答案）为圆心，则圆心一定在任意一条直径上，
且当直径长度为偶数（直径上的点为奇数个）时，圆心是直径中心点，
当直径长度为奇数（直径上的点为偶数个）时，圆心是直径中心的两个点

有了以上结论，不难想到本题的思路：
1. 根据已有的节点和边信息，建立有效的邻居查找结构（时间复杂度为O(n)，其中n为节点个数，显然边个数为n - 1）
2. 在任意节点（不妨从第一个节点）开始一次BFS（广度优先搜索），找到直径的一个端点（BFS的出入队、访问等操作均摊至每个节点是常数次，因此也是O(n)）
3. 再从找到的端点出发，开始一次BFS，确定一条直径（O(n)）
4. 从这条直径上面找到中心点，即为本题答案。（由于路径长度不可能超过n - 1，故O(n)）

这里的第2、3步都需要BFS，但有所不同的是，第2步的BFS只需要返回最后访问的端点即可，
而第3步的BFS还要记录下所走的路径信息，以便通过回溯找到圆心的位置。所以，第3步的BFS需要记忆功能。
好在，我们每次BFS形成的是一个树结构，特点是每个节点都只有一个父亲节点。因此只需要一个长度为n的parents向量，
每次访问节点时都把他所有孩子序号对应在parents中的位置的值标记为当前节点的序号，全部完成后即可通过孩子节点序号找到父亲。

以下是C++实现，两次BFS分开以方便分清功能上的区别。

作者：susummit
链接：https://leetcode-cn.com/problems/minimum-height-trees/solution/9963onfu-za-du-jie-ti-si-lu-xiang-jie-fu-xiang-xi-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
#include"pch.h"
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct myGraphNode {
	bool visited;
	std::vector<int> neibor;	
};

inline void resetVisitedSign(myGraphNode *myGraph, int n) {
	for (int i = 0; i < n; i++)
		myGraph[i].visited = false;
}

int basicBFS(myGraphNode *myGraph, int n) {  //普通版BFS，返回最后一个访问节点（直径的一端）
	int i, ret;                              //循环次数标签,节点变量，同时用于BFS结束的返回
	queue<int>q;                             //BFS所需队列
	q.push(0);                              //将任意节点（此处取0节点）入队
	while (!q.empty()) {                     //在队空之前
		ret = q.front();                     //取出队首节点
		myGraph[ret].visited = true;         //标记为visited
		q.pop();                             //并将其出队
		for (i = 0; i < myGraph[ret].neibor.size(); i++) {//遍历该节点图中的每一个邻居
			if (!myGraph[myGraph[ret].neibor[i]].visited) //如果没有访问过
				q.push(myGraph[ret].neibor[i]);           //则将其入队
		}
	}
	resetVisitedSign(myGraph, n);
	return ret;    //返回最后一个访问的节点
}

vector<int> routeRecordBFS(int startPoint, myGraphNode *myGraph, int n) {//记忆路径的BFS
	int i, j;  //循环次数标签
	int thisPoint;  //节点变量，当前访问节点
	int sizeOfThisLayer;  //当前层节点个数变量，用以控制队列出队次次数
	int *parents = new int[n];//父親記憶向量，记忆每个节点的父亲，便于回溯
	vector<int>ret;  //返回值
	int high = 0;    //最长路径上点的个数，随层次遍历而增长
	queue<int>q;  //BFS所需队列
	q.push(startPoint);//将来自上次的BFS的直径一段作为起点入队
	while (!q.empty()) { //在队空之前
		high++;  //没循环一层，高度加一
		sizeOfThisLayer = q.size();  //先记录当前队列中节点个数（本层节点数）
		for (i = 0; i < sizeOfThisLayer; i++) {//对于本层每个节点
			thisPoint = q.front();  //逐个取出
			myGraph[thisPoint].visited = true;//标记为visited
			q.pop();   //并从队列中弹出
			for (j = 0; j < myGraph[thisPoint].neibor.size(); j++) { //对于每个节点的邻居
				if (!myGraph[myGraph[thisPoint].neibor[j]].visited) {//如果没有被访问过
					q.push(myGraph[thisPoint].neibor[j]);  //则入队
					parents[myGraph[thisPoint].neibor[j]] = thisPoint;//并且将当前节点标记为其父亲
				}
			}
		}
	}
	if (high & 1) {
		for (i = 0; i < high / 2; i++) {
			thisPoint = parents[thisPoint];
		}
		ret.push_back(thisPoint);
	}
	else
	{
		for (i = 0; i < (high - 1) / 2; i++) {
			thisPoint = parents[thisPoint];
		}
		ret.push_back(thisPoint);
		thisPoint = parents[thisPoint];
		ret.push_back(thisPoint);
	}
	return ret;
}

//题2 返回给定的前序和后序遍历匹配的任何二叉树，pre和posr遍历中的值是不同的正整数
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x),left(NULL),right(NULL){}
};


class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector < vector<int>>&edges) {
		if (n == 0)return{};
		int i;
		myGraphNode *myGraph = new myGraphNode[n];
		resetVisitedSign(myGraph, n);
		for (i = 0; i < edges.size(); i++) {
			myGraph[edges[i][0]].neibor.push_back(edges[i][1]);
			myGraph[edges[i][1]].neibor.push_back(edges[i][0]);
		}
		return routeRecordBFS(basicBFS(myGraph, n), myGraph, n);
	}
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {

	}
	TreeNode* Solve(vector<int>&pre, vector<int>&post, int prbegin, int prend, int pobegin, int poend) {
		if (prbegin == prend) {
			TreeNode *root = new TreeNode(pre[prbegin]);
			return root;
		}
		if (prbegin > prend&&pobegin > poend) return nullptr;
		int left_child = pre[prbegin + 1];
		int right_child = post[poend-1];
		TreeNode *root = new TreeNode(pre[prbegin]);
		if (left_child != right_child) {
			int pos = 0;
			for (; pre[pos] != right_child; pos++);

			int leftLen = pos - prbegin - 1;
			int rightLen = prend - pos + 1;
			if (leftLen > 0) {
				root->left = Solve(pre, post, prbegin + 1, prbegin + leftLen, pobegin, pobegin + leftLen - 1);
			}
			if (rightLen > 0) {
				root->right = Solve(pre, post, prbegin + leftLen + 1, prend, pobegin + leftLen, poend - 1);
			}
			else if (left_child == right_child) {
				root->left = Solve(pre, post, prbegin + 1, prend, pobegin, poend - 1);
			}
			return root;
		}


	}
};



