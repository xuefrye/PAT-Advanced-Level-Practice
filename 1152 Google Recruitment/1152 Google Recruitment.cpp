/*
1152 Google Recruitment
2019年2月11日00:41:11
注意点
1.注意审题!!!题目要求输出要有前导0.但是我没仔细审题导致一个检查点不过.其实从string转成int后前导0消失,要输出前导0没那么麻烦直接输入原来的字符串就行..
2.看题意的运算量决定是直接算素数还是制表算.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
using namespace std;
const int maxn = 100000;
bool prime[maxn] = { 0 };

bool is_prime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false;
	return true;
}

int main()
{
	int l, k, num;
	char format[10];
	string str;
	cin >> l >> k >> str;
	sprintf(format, "%%0%dd", k);
	//cout << format;
	if (l == 0)
	{
		cout << 404;
		return 0;
	}

	for (int i = 0; i <= l - k;i++)
	{
		num = stoi(str.substr(i, k));
		if (is_prime(num))
		{ 
			printf("%.*d", k,num);
			return 0;
		}
	}

	cout << 404;
	return 0;
}