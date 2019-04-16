/*
1057 Stack £¨30 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn = 1e5 + 1;

int n,p;
//int stk[maxn];
vector<int> stk,tempstk;
string cmd;
int table[maxn] = { 0 };

int main()
{
	int sqrtmaxn = sqrt(double(maxn));
	vector<int> block(sqrtmaxn+1);
	int number;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "Push")
		{
			scanf("%d", &number);
			stk.push_back(number);
			table[number]++;
			block[number / sqrtmaxn]++;
		}
		else if (cmd == "Pop")
		{
			if (stk.size() == 0)
			{
				printf("Invalid\n");
			}
			else
			{
				number = stk[stk.size() - 1];
				printf("%d\n", number);
				stk.pop_back();
				table[number]--;
				block[number / sqrtmaxn]--;
			}
		}
		else if (cmd == "PeekMedian")
		{
			int id, sum = 0,number=0,blockid =0;
			if (stk.size() == 0)
			{
				printf("Invalid\n");
			}
			else
			{
				if (stk.size() % 2 == 0)
				{
					id = (stk.size() / 2);

				}
				else
				{
					id = ((stk.size()+1 )/ 2);
				}

				while (block[blockid] + sum < id)
				{
					sum += block[blockid++];
				}
				number = blockid * sqrtmaxn;

				while (sum + table[number] < id)
				{
					sum += table[number++];
				}
				printf("%d\n", number);
			}
		}
	}
	system("pause");
}