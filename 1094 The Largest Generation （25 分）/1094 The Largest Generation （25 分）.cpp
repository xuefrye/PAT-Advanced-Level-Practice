/*
1094 The Largest Generation （25 分）
注意点
1.记录节点和节点的个数，只需要建表table[i]表示第i层有多少个节点，然后在dfs中++最后遍历表就行了.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 110;

struct node
{
	int id;
	int layer = 0;
	vector<int> child;
}tree[maxn];

int n, m;
int k,id,childid;
int maxlayer, templayer, maxcnt,cnt=1;

int table[maxn] = { 0 };
int maxvalue = 0, maxlevel = 0;


bool compare(node &a, node &b)
{
	return a.layer > b.layer;
}
void bfs(int id,int layer)
{
	table[layer]++;
	tree[id].layer = layer;
	if (tree[id].child.size() == 0)
	{
		return;
	}
	for (int i = 0; i < tree[id].child.size(); i++)
	{
		bfs(tree[id].child[i], layer+1);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &id,&k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &childid);
			tree[id].id = id;
			tree[id].child.push_back(childid);
		}
	}

	bfs(01, 1);
	//sort(tree, tree + maxn, compare);

	//for (int i = 1 ; i <= n; i++)
	//{
	//	if(i==n && cnt > maxcnt)
	//	{
	//		maxcnt = cnt;
	//		cnt = 1;
	//		maxlayer = tree[i - 1].layer;
	//		break;
	//	}
	//	if(tree[i].layer == tree[i-1].layer)
	//		cnt++;
	//	else 
	//	{
	//		if (cnt > maxcnt)
	//		{
	//			maxcnt = cnt;
	//			cnt = 1;
	//			maxlayer = tree[i - 1].layer;
	//		}
	//	}
	//}

	for (int i = 0; i < maxn; i++)
	{
		if (table[i] > maxlevel)
		{ 
			maxvalue = table[i];
			maxlevel = i;
		}
	}
	printf("%d %d", maxvalue, maxlevel);
	//printf("%d %d", maxcnt, maxlayer);
	system("pause");
}
