/*
1134 Vertex Cover £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int maxn = 1e5 + 10;
int n, m, k;
int e1, e2;
int nv,vi;

struct link
{
	int e1;
	int e2;
	link(int a,int b):e1(a),e2(b){}
};

vector<link> edge;
vector<int> nodes;

vector<int> adj[maxn];
bool h[maxn];
bool exist[maxn] = { false };

void compare(int x)
{
	for (int i = 0; i < m; i++)
	{
		if (x == edge[i].e1 || x == edge[i].e2)
		{
			exist[i] = true;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &e1, &e2);
		//edge.push_back(link(e1, e2));
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &nv);
		nodes.clear();
		//fill(exist, exist + maxn, false);
		fill(h, h + maxn, false);
		for (int j = 0; j < nv; j++)
		{
			scanf("%d", &vi);
			nodes.push_back(vi);
		}

		for (int x = 0; x < nv; x++)
		{
			//compare(nodes[x]);
			h[x] = true;
			for (int y = 0; y < adj[h[x]].size(); y++)
			{
				h[adj[h[x]][y]] = true;
			}
		}

		bool flag = true;
		for (int x = 0; x < n; x++)
		{
			if (h[x] == false)
			{
				flag = false; break;
			}
		}

		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	system("pause");
}