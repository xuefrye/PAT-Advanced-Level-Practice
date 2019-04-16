/*
1143 Lowest Common Ancestor £¨30 ·Ö£©
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<int, bool> exist;
const int maxn = 50010;
int m, n, u, v;
vector<int> pre(maxn);
int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pre[i];
		exist[pre[i]] = true;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		if(exist[u] == false && exist[v] == false)
		{
			printf("ERROR: %d and %d are not found.\n", u, v);
		}
		else if (exist[u] == false)
		{
			printf("ERROR: %d is not found.\n", u);
		}
		else if (exist[v] == false)
		{
			printf("ERROR: %d is not found.\n", v);
		}
		else
		{
			for (int x = 0; x < n; x++)
			{
				int now = pre[x];
				if (now >= u && now <= v || now >= v && now <= u)
				{
					int lca = now;
					if (lca != u && lca != v)
					{
						printf("LCA of %d and %d is %d.\n", u, v, lca); break;
					}
					else if (lca == u) {
						printf("%d is an ancestor of %d.\n", u, v); break;
					}
					else
					{
						printf("%d is an ancestor of %d.\n", v, u); break;
					}
				}
			}
		}
	}
}
