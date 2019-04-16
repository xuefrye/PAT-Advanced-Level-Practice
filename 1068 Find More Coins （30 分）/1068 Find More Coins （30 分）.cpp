/*
1068 Find More Coins £¨30 ·Ö£©
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int n, m;
int coin[maxn];
bool visited[maxn] = { false };
vector<int> choice, ansChoice; bool first = true; bool flag = false;

void dfs(int idx, int sum)
{
	if (flag) return;
	visited[idx] = true;
	if (idx == n)
	{
		if(sum==m)
		{
			flag = true;
			if (first)
			{
				ansChoice = choice;
				first = false;
			}
		}
		return;
	}

	if (sum + coin[idx] <= m && visited[idx+1] == false)
	{
		choice.push_back(coin[idx]);
		dfs(idx + 1, sum + coin[idx]);
		choice.pop_back();
	}
	dfs(idx + 1, sum);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}
	sort(coin, coin + n);
	dfs(0,0);
	if (ansChoice.size() == 0)
	{
		printf("No Solution\n");
	}
	else
	{
		printf("%d",ansChoice[0]);
		for(int i=1;i<ansChoice.size();i++)
			printf(" %d", ansChoice[i]);
	}
	system("pause");
}