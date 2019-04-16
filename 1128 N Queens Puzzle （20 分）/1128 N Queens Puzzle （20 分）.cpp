/*
1128 N Queens Puzzle £¨20 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

const int maxn = 1010;
int q[maxn] = { 0 };
unordered_set<int> qcnt;

int main()
{
	int n, k; bool flag = true;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		qcnt.clear();
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &q[j]);
			qcnt.insert(q[j]);
		}

		if (qcnt.size() != n)
		{
			printf("NO\n");
			continue;
		}
		else
		{
			flag = true;
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (j - i == abs(q[j] - q[i]))
					{
						printf("NO\n");
						flag = false;
						break;
					}
				}
				if (flag == false)
					break;
			}
		}

		if(flag)
			printf("YES\n");
	}

}