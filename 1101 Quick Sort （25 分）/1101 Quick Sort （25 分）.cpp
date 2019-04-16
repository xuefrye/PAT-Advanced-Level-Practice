/*
1101 Quick Sort £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e6;
int lmax[maxn],maxNum = -1;
int rmin[maxn],minNum = 1e9+10;
int in[maxn];
int n;
vector<int> ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
		if (in[i] > maxNum)
		{
			maxNum = in[i];
		}
		lmax[i] = maxNum;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (in[i] < minNum)
		{
			minNum = in[i];
		}
		rmin[i] = minNum;
	}

	for (int i = 0; i < n; i++)
	{
		if (in[i] == rmin[i] && in[i] == lmax[i])
		{
			ans.push_back(in[i]);
		}
	}
	if (ans.size() == 0)
	{
		printf("\n"); return 0;
	}

	printf("%d\n", ans.size());
	printf("%d", ans[0]);
	for (int i = 1; i < ans.size(); i++)
		printf(" %d", ans[i]);
}