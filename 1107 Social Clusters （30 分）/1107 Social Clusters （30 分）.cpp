/*
1107 Social Clusters （30 分）
注意点
1.这道题是通过兴趣找人,所以集合是由人作为元素的!!!
2.并查集的基本思路是,你能通过任意一个元素向上查找,最终都能找到根节点!!
所以这里是通过兴趣找人!!建立一个数组hobby[i],i是兴趣编号,输出任意一个有这个兴趣的人的id就行了!!!
找到了人,也就找到了集合.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
const int maxn = 2010;
int hobby[maxn] = { 0 };
int father[maxn];
int n,k,h;
int cnt=0;
int isRoot[maxn] = { 0 };

bool cmp(int &a, int &b)
{
	return a > b;
}

void init()
{
	for (int i = 1; i <= n; i++)
		father[i] = i;
}

int findRoot(int id)
{
	while (father[id] != id)
		id = father[id];
	return id;
}

void Union(int a, int b)
{
	int roota = findRoot(a);
	int rootb = findRoot(b);
	if (roota != rootb)
		father[roota] = rootb;
}

int main()
{
	cin >> n;
	init();
	for (int i = 1; i <= n; i++)
	{
		scanf("%d:", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &h);
			if (hobby[h] == 0)
				hobby[h] = i;
			Union(i, findRoot(hobby[h]));
		}
	}

	for (int i = 1; i <= n; i++)
	{
		isRoot[findRoot(i)]++;
	}


	for (int i = 1; i <= n; i++)
	{
		if (isRoot[i] != 0)
			cnt++;
	}

	printf("%d\n", cnt);
	sort(isRoot + 1, isRoot + n + 1, cmp);
	printf("%d", isRoot[1]);
	for (int i = 2; i <= cnt; i++)
		printf(" %d", isRoot[i]);
	system("pause");
}