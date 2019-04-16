/*
1105 Spiral Matrix £¨25 ·Ö£©
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int maxn = 1e5 + 10;
int input[maxn];
int G[1000][1000];



struct node
{
	int m;
	int n;
	int sub;
	node(int a, int b, int c)
	{
		m = a;
		n = b;
		sub = c;
	}
};

bool cmp(int &a, int &b)
{
	return a > b;
}

bool cmp2(node &a, node &b)
{
	return a.sub < b.sub;
}

vector<node> ans;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	sort(input, input + n,cmp);
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
		{
			if (i >= n / i)
			{
				ans.push_back(node(i, n / i, i - n / i));
			}
		}
	}
	sort(ans.begin(), ans.end(), cmp2);
	int r = ans[0].m ,l = ans[0].n;

	int nl = 0, nr = l - 1, mu = 0, md = r - 1;
	int cnt = 0;
	while (1)
	{
		for (int i = nl; i <= nr; i++)
		{
			G[mu][i] = input[cnt++];
		}
		mu++; if (cnt == n) break;
		for (int i = mu; i <= md; i++)
		{
			G[i][nr] = input[cnt++];
		}
		nr--; if (cnt == n) break;
		for (int i = nr; i >= nl; i--)
		{
			G[md][i] = input[cnt++];
		}
		md--; if (cnt == n) break;
		for (int i = md; i >= mu; i--)
		{
			G[i][nl] = input[cnt++];
		}
		nl++; if (cnt == n) break;
	}

	for (int i = 0; i < r; i++)
	{
		bool first = true;
		for (int j = 0; j < l; j++)
		{
			if (first)
			{
				printf("%d", G[i][j]);
				first = false;
			}
			else
				printf(" %d", G[i][j]);
		}
		printf("\n");
	}
	system("pause");
}

