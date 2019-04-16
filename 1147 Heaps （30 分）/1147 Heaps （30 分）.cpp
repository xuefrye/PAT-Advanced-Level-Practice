/*
1147 Heaps £¨30 ·Ö£©
*/
#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool first = true;
vector<int> tree(1010);

void postOrder(int root)
{
	if (root > n)
		return;

	postOrder(root * 2);
	postOrder(root * 2 + 1);
	if (first)
	{
		printf("%d", tree[root]); first = false;
	}
	else printf(" %d", tree[root]);
}

void judege(vector<int> &v)
{
	int  isMax = true, isMin = true;
	for (int i = 1; i <= n / 2; i++)
	{
		int father = v[i]; int  maxChild = v[i * 2]; int minChild = v[i * 2];
		if (i * 2 + 1 <= n && maxChild < v[i * 2 + 1])
			maxChild = v[i * 2 + 1];
		if (i * 2 + 1 <= n && minChild > v[i * 2 + 1])
			minChild = v[i * 2 + 1];

		if (father < maxChild)
			isMax = false;
		if (father > minChild)
			isMin = false;

		if (isMax == false && isMin == false)
		{
			printf("Not Heap\n"); return;
		}
	}

	if (isMax == true)
		printf("Max Heap\n");
	else
		printf("Min Heap\n");
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> tree[j];

		judege(tree);
		postOrder(1);
		printf("\n"); first = true;
	}
	system("pause");
}