//����һ������������������ͼ�����ǿ���ѡ���κ�һ���ڵ���Ϊ����
//ͼ��˿��Գ�Ϊ���������п��ܵ�����,������С�߶ȵ�����Ϊ��С�߶�����
//����������ͼ��д��һ�������е�������С�߶������������ǵĸ��ڵ�
/*������������ǡ�������������ͼ����������ͼ�����������¼������ۣ����ڵ˿��Խ��ڵġ����ݽṹϰ�⼯��6-9��6-10����ϸ֤����

1. ���� = ������ - 1��ÿ����һ���¶���ֻ������һ���±ߣ��������ֻ�·��
2. ����ȫͼ�·��Ϊֱ������ֱ������һ��Ψһ���������˵�һ��������Ҷ�ӽڵ�
3. ������ڵ�����Ĺ�������������һ���ڵ�һ����ֱ���Ķ˵�
4. ����ȫͼ�����������ڵ����������С�Ľڵ㣨ע�⣡����Ҫ�ҵ������ĸ��ڵ�Ϊ���γ����߶���С��
����������ȼۣ��������нڵ���ʵ���Ǳ�����Ѱ�ҵĴ𰸣�ΪԲ�ģ���Բ��һ��������һ��ֱ���ϣ�
�ҵ�ֱ������Ϊż����ֱ���ϵĵ�Ϊ��������ʱ��Բ����ֱ�����ĵ㣬
��ֱ������Ϊ������ֱ���ϵĵ�Ϊż������ʱ��Բ����ֱ�����ĵ�������

�������Ͻ��ۣ������뵽�����˼·��
1. �������еĽڵ�ͱ���Ϣ��������Ч���ھӲ��ҽṹ��ʱ�临�Ӷ�ΪO(n)������nΪ�ڵ��������Ȼ�߸���Ϊn - 1��
2. ������ڵ㣨�����ӵ�һ���ڵ㣩��ʼһ��BFS������������������ҵ�ֱ����һ���˵㣨BFS�ĳ���ӡ����ʵȲ�����̯��ÿ���ڵ��ǳ����Σ����Ҳ��O(n)��
3. �ٴ��ҵ��Ķ˵��������ʼһ��BFS��ȷ��һ��ֱ����O(n)��
4. ������ֱ�������ҵ����ĵ㣬��Ϊ����𰸡�������·�����Ȳ����ܳ���n - 1����O(n)��

����ĵ�2��3������ҪBFS����������ͬ���ǣ���2����BFSֻ��Ҫ���������ʵĶ˵㼴�ɣ�
����3����BFS��Ҫ��¼�����ߵ�·����Ϣ���Ա�ͨ�������ҵ�Բ�ĵ�λ�á����ԣ���3����BFS��Ҫ���书�ܡ�
���ڣ�����ÿ��BFS�γɵ���һ�����ṹ���ص���ÿ���ڵ㶼ֻ��һ�����׽ڵ㡣���ֻ��Ҫһ������Ϊn��parents������
ÿ�η��ʽڵ�ʱ���������к�����Ŷ�Ӧ��parents�е�λ�õ�ֵ���Ϊ��ǰ�ڵ����ţ�ȫ����ɺ󼴿�ͨ�����ӽڵ�����ҵ����ס�

������C++ʵ�֣�����BFS�ֿ��Է�����幦���ϵ�����

���ߣ�susummit
���ӣ�https://leetcode-cn.com/problems/minimum-height-trees/solution/9963onfu-za-du-jie-ti-si-lu-xiang-jie-fu-xiang-xi-/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������*/
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

int basicBFS(myGraphNode *myGraph, int n) {  //��ͨ��BFS���������һ�����ʽڵ㣨ֱ����һ�ˣ�
	int i, ret;                              //ѭ��������ǩ,�ڵ������ͬʱ����BFS�����ķ���
	queue<int>q;                             //BFS�������
	q.push(0);                              //������ڵ㣨�˴�ȡ0�ڵ㣩���
	while (!q.empty()) {                     //�ڶӿ�֮ǰ
		ret = q.front();                     //ȡ�����׽ڵ�
		myGraph[ret].visited = true;         //���Ϊvisited
		q.pop();                             //���������
		for (i = 0; i < myGraph[ret].neibor.size(); i++) {//�����ýڵ�ͼ�е�ÿһ���ھ�
			if (!myGraph[myGraph[ret].neibor[i]].visited) //���û�з��ʹ�
				q.push(myGraph[ret].neibor[i]);           //�������
		}
	}
	resetVisitedSign(myGraph, n);
	return ret;    //�������һ�����ʵĽڵ�
}

vector<int> routeRecordBFS(int startPoint, myGraphNode *myGraph, int n) {//����·����BFS
	int i, j;  //ѭ��������ǩ
	int thisPoint;  //�ڵ��������ǰ���ʽڵ�
	int sizeOfThisLayer;  //��ǰ��ڵ�������������Կ��ƶ��г��Ӵδ���
	int *parents = new int[n];//���Hӛ������������ÿ���ڵ�ĸ��ף����ڻ���
	vector<int>ret;  //����ֵ
	int high = 0;    //�·���ϵ�ĸ��������α���������
	queue<int>q;  //BFS�������
	q.push(startPoint);//�������ϴε�BFS��ֱ��һ����Ϊ������
	while (!q.empty()) { //�ڶӿ�֮ǰ
		high++;  //ûѭ��һ�㣬�߶ȼ�һ
		sizeOfThisLayer = q.size();  //�ȼ�¼��ǰ�����нڵ����������ڵ�����
		for (i = 0; i < sizeOfThisLayer; i++) {//���ڱ���ÿ���ڵ�
			thisPoint = q.front();  //���ȡ��
			myGraph[thisPoint].visited = true;//���Ϊvisited
			q.pop();   //���Ӷ����е���
			for (j = 0; j < myGraph[thisPoint].neibor.size(); j++) { //����ÿ���ڵ���ھ�
				if (!myGraph[myGraph[thisPoint].neibor[j]].visited) {//���û�б����ʹ�
					q.push(myGraph[thisPoint].neibor[j]);  //�����
					parents[myGraph[thisPoint].neibor[j]] = thisPoint;//���ҽ���ǰ�ڵ���Ϊ�丸��
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

//��2 ���ظ�����ǰ��ͺ������ƥ����κζ�������pre��posr�����е�ֵ�ǲ�ͬ��������
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



