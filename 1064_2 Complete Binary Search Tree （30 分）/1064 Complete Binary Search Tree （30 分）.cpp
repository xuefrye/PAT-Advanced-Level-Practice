/*
1064 Complete Binary Search Tree ��30 �֣�
˼·.��Ϊ��������������������������.
������ȫ������������������.���ڵ���1,����2i,�Һ���2i+1,���i>n��ΪNULL��
˼�룺��֪�������У�������������ڡ����������ڱ�����ʱ����������ֵ��
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