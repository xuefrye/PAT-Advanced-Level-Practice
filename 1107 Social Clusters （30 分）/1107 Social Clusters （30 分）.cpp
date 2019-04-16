/*
1107 Social Clusters ��30 �֣�
ע���
1.�������ͨ����Ȥ����,���Լ�����������ΪԪ�ص�!!!
2.���鼯�Ļ���˼·��,����ͨ������һ��Ԫ�����ϲ���,���ն����ҵ����ڵ�!!
����������ͨ����Ȥ����!!����һ������hobby[i],i����Ȥ���,�������һ���������Ȥ���˵�id������!!!
�ҵ�����,Ҳ���ҵ��˼���.
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