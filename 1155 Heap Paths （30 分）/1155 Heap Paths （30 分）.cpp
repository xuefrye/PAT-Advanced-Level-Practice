/*
1155 Heap Paths £¨30 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> path,temp;

int n;
int heap[1010];

void dfs(int id)
{
	if (id * 2 > n)
	{
		path.push_back(heap[id]);
		bool first = true;
		for (int i = 0; i < path.size(); i++)
		{
			if (first)
			{
				first = false;
				printf("%d", path[i]);
			}
			else
				printf(" %d",path[i]);
		}
		printf("\n");
		path.pop_back();
		return;
	}
	if (id * 2 +1<= n)
	{
		path.push_back(heap[id]);
		dfs(id * 2 + 1);
		path.pop_back();
	}
	if (id*2<=n)
	{
		path.push_back(heap[id]);
		dfs(id * 2);
		path.pop_back();
	}
}


int main()
{
	//freopen("1155.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> heap[i];
	}
	dfs(1);
	
	bool is_max = true;
	for (int i = 1; i <= n/2; i++)
	{
		int father = heap[i];
		int child = heap[i * 2];
		if (i * 2 + 1 <= n && child < heap[i * 2 + 1])
			swap(child, heap[i * 2 + 1]);
		if (father < child)
		{
			is_max = false; break;
		}
	}
	if (is_max)
	{
		printf("Max Heap"); system("pause");
		return 0;
	}

	bool is_min = true;
	for (int i = 1; i <= n / 2; i++)
	{
		int father = heap[i];
		int child = heap[i * 2];
		if (i * 2 + 1 <= n && child > heap[i * 2 + 1])
			swap(child, heap[i * 2 + 1]);
		if (father > child)
		{
			is_min = false;
			break;
		}
	}
	if (is_min)
	{
		printf("Min Heap"); system("pause");
		return 0;
	}

	printf("Not Heap");
	system("pause");
}