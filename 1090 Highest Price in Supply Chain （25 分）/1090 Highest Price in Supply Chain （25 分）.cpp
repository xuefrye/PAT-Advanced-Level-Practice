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
int father[maxn];
int n;
double p, r;
int is_leaf[maxn];
vector<int> leaf;
int number = 1,maxcnt=0,cnt=0;


int main()
{
	fill(is_leaf, is_leaf + maxn, true);
	cin >> n >> p >> r;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &father[i]);
		if (father[i] != -1)
			is_leaf[father[i]] = false;
		else
			is_leaf[i] = false;
	}

	for (int i = 0; i < n; i++)
	{
		if (is_leaf[i] == true)
			leaf.push_back(i);
	}

	for (int i = 0; i < leaf.size(); i++)
	{
		int temp = leaf[i];
		cnt = 0;
		while (father[temp] != -1)
		{
			cnt++;
			temp = father[temp];
		}
		if (cnt > maxcnt)
		{
			maxcnt = cnt;
			number = 1;
		}

		else if (cnt == maxcnt)
		{
			number++;
		}
	}
	printf("%.2lf %d", p * pow(1.0 + r/100.0, maxcnt), number);
	system("pause");
}