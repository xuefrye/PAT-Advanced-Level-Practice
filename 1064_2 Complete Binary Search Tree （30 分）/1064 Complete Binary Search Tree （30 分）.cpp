/*
1064 Complete Binary Search Tree （30 分）
思路.因为二叉搜索树的中序遍历是有序的.
而且完全二叉树可以用数组存放.根节点是1,左孩子2i,右孩子2i+1,如果i>n则为NULL。
思想：已知中序序列，假设这个树存在。遍历他，在遍历的时候对这棵树赋值。
*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
const int maxn = 10010;
int tree[maxn];
int n;
int ctree[maxn],cnt=0;


void inOrder(int root)
{
	if (root > n)
		return;

	inOrder(2 * root);
	ctree[root] = tree[cnt++];
	inOrder(2 * root + 1);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> tree[i];

	sort(tree, tree + n);
	inOrder(1);
	for (int i = 1; i <= n; i++)
		printf("%d ", ctree[i]);
	system("pause");
}