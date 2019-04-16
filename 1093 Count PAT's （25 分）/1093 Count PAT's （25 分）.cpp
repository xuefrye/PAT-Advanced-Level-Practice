/*
1093 Count PAT's ��25 �֣�
ע���
1.���������λ����sum������ٶ�sum����
����sum���������+=
��ôֻ�ܵȵ���һ����ٶ�sum mod 100000007.
*/
#include<iostream>
#include<string>
using namespace std;

const int maxn = 1e5 + 1;
int pcnt = 0;
int pleft[maxn] = { 0 };
int tcnt = 0;
int tright[maxn] = { 0 };

int main()
{
	string input;
	cin >> input;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 'P')
			pleft[i] = ++pcnt;
		else
			pleft[i] = pcnt;
	}

	for (int i = input.size()-1; i >= 0 ; i--)
	{
		if (input[i] == 'T')
			tright[i] = ++tcnt;
		else
			tright[i] = tcnt;
	}

	long long sum = 0;
	for (int i = 1; i < input.size()-1; i++)
	{
		if (input[i] == 'A')
		{
			sum += (pleft[i] * tright[i]);
			sum %= 1000000007;
		}
		
	}

	cout << sum;
	system("pause");
}