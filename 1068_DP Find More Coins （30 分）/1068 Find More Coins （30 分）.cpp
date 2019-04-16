#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1e4+10;
int n, m;
int coin[maxn];


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	sort(coin + 1, coin + 1 + n, greater<int>());

}