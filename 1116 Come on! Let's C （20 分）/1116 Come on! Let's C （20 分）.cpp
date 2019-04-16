/*
1116 Come on! Let's C （20 分）

1处低级失误debug10分钟

*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<cmath>

using namespace std;
map<int, int> id2rank;
map<int, int> rank2id;
int n, k, id;
bool visited[10010] = { false };

bool prime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	//freopen("1116.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> id;
		rank2id[i] = id;
		id2rank[id] = i;
	}

	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> id;
		if (visited[id] == true && id2rank[id] != 0)
		{
			printf("%04d: Checked\n", id);
		}
		else if (id2rank[id] == 0)
		{
			printf("%04d: Are you kidding?\n", id);
		}
		else if (id2rank[id] == 1)
		{
			printf("%04d: Mystery Award\n", id);
			visited[id] = true;
		}
		else if(prime(id2rank[id]))
		{
			printf("%04d: Minion\n", id);
			visited[id] = true;
		}
		else
		{
			printf("%04d: Chocolate\n", id);
			visited[id] = true;
		}
	}
}