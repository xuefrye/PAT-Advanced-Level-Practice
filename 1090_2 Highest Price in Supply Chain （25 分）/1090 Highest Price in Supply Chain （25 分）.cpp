/*
1090 Highest Price in Supply Chain £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

const int maxn = 100001;
int n,fatherid,root;
double p, r;
vector<int> tree[maxn];
int templayer, maxlayer = 0, pathNum = 1;

void dfs(int root,int layer)
{
	if (tree[root].size() == 0)
	{
		if (layer > maxlayer)
		{
			maxlayer = layer;
			pathNum = 1;
		}
		else if (layer == maxlayer)
			pathNum++;
		return;
	}

	for (int i = 0; i < tree[root].size(); i++)
		dfs(tree[root][i], layer + 1);
}

int main()
{
	scanf("%d %lf %lf", &n, &p, &r);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &fatherid);
		if (fatherid != -1)
			tree[fatherid].push_back(i);
		else if (fatherid == -1)
			root = i;
	}
	dfs(root, 1);

	printf("%.2lf %d", p*pow(1 + r / 100.0, maxlayer-1), pathNum);
}