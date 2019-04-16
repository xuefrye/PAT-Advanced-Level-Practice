/*
1145 Hashing - Average Search Time £¨25 ·Ö)
*/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
const int maxn = 1e5 + 10;
int msize, m, n;
bool has[maxn] = { false };
int hashTable[maxn];
double sum = 0;
int in;

int isPrime(int num)
{
	if (num <= 1)
		return false;

	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}

int genPrime(int num)
{
	while (true)
	{
		if (isPrime(num))
			return num;
		else
			num++;
	}
}

int h(int num)
{
	int input = num;int i = 0;
	for (int i = 0; i < msize; i++)
	{
		int pos = (num + i * i) % msize;
		if (hashTable[pos] == 0)
		{
			hashTable[pos] = num;
			return pos;
		}
	}
	printf("%d cannot be inserted.\n", num);
}

int findNum(int num)
{
	int ans = 0;
	for (int i = 0; i <= msize; i++)
	{
		ans++;
		int pos = (num + i * i) % msize;
		if (hashTable[pos] == num || hashTable[pos] == 0)
			break;
	}
	return ans;
}

int main()
{
	cin >> msize >> n >> m;
	msize = genPrime(msize);
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		h(in);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> in;
		sum += findNum(in);
	}
	printf("%.1lf", sum / m);
	system("pause");
}