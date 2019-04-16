/*
1152 Google Recruitment
2019��2��11��00:41:11
ע���
1.ע������!!!��ĿҪ�����Ҫ��ǰ��0.������û��ϸ���⵼��һ�����㲻��.��ʵ��stringת��int��ǰ��0��ʧ,Ҫ���ǰ��0û��ô�鷳ֱ������ԭ�����ַ�������..
2.�������������������ֱ�������������Ʊ���.
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