/*
1117 Eddington Number £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int mile[maxn];
int n,e;
int notZero=0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &mile[i]);
	}

	sort(mile, mile + n);

	e = 1;
	for (int i = n-1; i >=0; i--)
	{
		if (e < mile[i])
		{
			e++;
		}
		else break;
	}
	cout << e-1;
	system("pause");
}