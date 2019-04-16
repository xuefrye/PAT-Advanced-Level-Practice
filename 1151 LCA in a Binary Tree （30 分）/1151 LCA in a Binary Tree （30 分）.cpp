/*
1151 LCA in a Binary Tree £¨30 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

const int maxn = 10010;
int in[maxn], pre[maxn];
unordered_map<int, int> idx;
int m, n, v, u;

void findLca(int root, int inL, int inR)
{
	int pos = idx[pre[root]];

	int lenL = pos - inL;

	if (idx[u] < pos && pos < idx[v] || idx[v] < pos && pos < idx[u])
		printf("LCA of %d and %d is %d.\n", u, v, in[pos]);
	else if (idx[u] < pos && idx[v] < pos)
		findLca(root+1, inL, pos - 1);
	else if (idx[u] > pos && idx[v] > pos)
		findLca(root+lenL+1, pos + 1, inR);
	else if (idx[u] == pos)
		printf("%d is an ancestor of %d.\n", u, v);
	else if (idx[v] == pos)
		printf("%d is an ancestor of %d.\n", v, u);
}
int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &in[i]);
		idx[in[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &pre[i]);

	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		if (idx[u] == 0 && idx[v] == 0)
		{
			printf("ERROR: %d and %d are not found.\n", u, v);
		}
		else if (idx[u] == 0)
		{
			printf("ERROR: %d is not found.\n", u);
		}
		else if (idx[v] == 0)
		{
			printf("ERROR: %d is not found.\n", v);
		}
		else
			findLca(1, 1, n);

	}
}