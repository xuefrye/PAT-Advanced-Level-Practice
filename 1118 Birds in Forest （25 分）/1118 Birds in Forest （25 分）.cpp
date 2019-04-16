/*
1118 Birds in Forest £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

const int maxn = 1e4 + 10;
unordered_map<int, bool> exist;
unordered_set<int> ex;
int n, k, birds[maxn], q, b1, b2;
int father[maxn];

void init()
{
	for (int i = 0; i < maxn; i++)
	{
		father[i] = i;
	}
}

int findRoot(int num)
{
	int son = num;
	while (father[num] != num)
	{
		num = father[num];
	}

	int temp = son;
	while (father[temp] != num)
	{
		temp = father[temp];
		father[son] = num;
		son = temp;
	}
	return num;
}

void Union(int a, int b)
{
	int roota = findRoot(a);
	int rootb = findRoot(b);
	if (roota != rootb)
	{
		father[roota] = rootb;
	}
}

int main()
{
	init();
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &birds[j]);
			Union(birds[0], birds[j]);
			ex.insert(birds[j]);
		}
	}

	int setCnt = 0;
	for (int i = 1; i <= ex.size(); i++)
	{
		if (i == findRoot(i))
			setCnt++;
	}

	printf("%d %d\n",setCnt, ex.size());
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &b1,&b2);
		if (findRoot(b1) != findRoot(b2))
			printf("No\n");
		else
			printf("Yes\n");
	}
}