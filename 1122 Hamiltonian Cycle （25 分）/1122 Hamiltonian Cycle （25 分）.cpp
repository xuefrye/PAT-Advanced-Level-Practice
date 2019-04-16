/*
1122 Hamiltonian Cycle £¨25 ·Ö£©
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
const int maxn = 500;
int G[maxn][maxn] = { 0 };
int n, m, k,v1, v2, vn, v;
vector<int> path(maxn);
int exist[maxn] = { 0 };
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> v1 >> v2;
		G[v1][v2] = G[v2][v1] = 1;
	}

	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> vn;
		fill(exist, exist + maxn, 0);
		for (int j = 0; j < vn; j++)
		{
			cin >> path[j];
			exist[path[j]]++;
		}
		exist[path[0]]--;

		bool flag = true;

		for (int j = 1; j <= n; j++)
		{
			if (exist[path[j]] != 1)
				flag = false;
		}

		for (int j = 1; j < vn; j++)
		{
			if (G[path[j]][path[j-1]] == 0)
			{
				flag = false;
				break;
			}
		}

		if (path[0] != path[vn - 1])
			flag = false;

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}

	system("pause");
}