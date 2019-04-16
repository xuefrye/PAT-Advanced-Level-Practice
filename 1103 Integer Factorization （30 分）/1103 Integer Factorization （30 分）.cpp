/*
1103 Integer Factorization £¨30 ·Ö£©
*/

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 410;
int n, k, p;
int maxFacSum = -1;
vector<int> ans,temp,temp0;
vector<int> powTable;
bool hasAns = false;

void dfs(int idx,int sum,int facSum,int nowK)
{
	if (nowK == k || sum >= n)
	{
		if (nowK == k &&sum == n && facSum > maxFacSum)
		{
			hasAns = true;
			maxFacSum = facSum;
			ans = temp;
		}
		return;
	}
	//if (nowK == k)
	//{
	//	if (sum == n && facSum > maxFacSum)
	//	{
	//		maxFacSum = facSum;
	//		ans = temp;
	//	}
	//	return;
	//}

	while (idx >= 1)
	{
		if (sum + powTable[idx] <= n)
		{
			temp.push_back(idx);
			dfs(idx, sum + powTable[idx], facSum + idx, nowK + 1);
			temp.pop_back();
		}
		idx--;
	}
}

void init()
{
	int temp = 0;
	for (int i = 0; temp <= n; i++)
	{
		temp = pow(i, p);
		powTable.push_back(temp);
	}
}

int main()
{
	cin >> n >> k >> p;
	init();
	dfs(powTable.size()-1,0,0,0);

	if (maxFacSum == -1)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < k; i++)
			printf(" + %d^%d", ans[i], p);
		printf("\n");
	}
	system("pause");
	//169 = 6 ^ 2 + 6 ^ 2 + 6 ^ 2 + 6 ^ 2 + 5 ^ 2
}