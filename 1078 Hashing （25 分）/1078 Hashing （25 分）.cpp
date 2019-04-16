/*
1078 Hashing £¨25 ·Ö£©
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int m, n,in;
int h[maxn];

bool isPrime(int num)
{
	if (num <= 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++)
		if (num%i == 0)
			return false;
	return true;
}

int Hash(int num)
{
	for (int i = 0; i < m; i++)
	{
		int pos = (num + i * i) % m;
		if (h[pos] == -1)
		{
			h[pos] = num;
			return pos;
		}
	}
	return -1;
}

int main()
{
	fill(h, h + maxn, -1);
	cin >> m >> n;
	while (!isPrime(m))
		m++;

	for (int i = 0; i < n; i++)
	{
		cin >> in;
		int pos = Hash(in);
		if (i == 0)
		{
			if (pos != -1)
			{
				printf("%d", pos);
			}
			else
				printf("-");
		}
		else
		{
			if (pos != -1)
			{
				printf(" %d", pos);
			}
			else
				printf(" -");
		}
	}
	system("pause");
}