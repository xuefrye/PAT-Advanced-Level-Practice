/*
1065 A+B and C (64bit) £¨20 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


int main()
{
	int n;
	long long a, b, c;
	scanf("%d", &n);
	//bool flag;
	//for (int i = 1; i <= n; i++)
	//{
	//	scanf("%lld %lld %lld", &a, &b, &c);
	//	long long res = a + b;
	//	if (a > 0 && b > 0 && res < 0) flag = true;
	//	else if ((a < 0 && b < 0 && res >= 0)) flag = false;
	//	else if(res > c)flag = true;
	//	else flag = false;

	//	if(flag)
	//		printf("Case #%d: true\n", i);
	//	else
	//		printf("Case #%d: false\n", i);
	//}

	for (int i = 1; i <= n; i++)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		long long res = a + b;
		if (a > 0 && b > 0)
		{
			if (res < 0)
				printf("Case #%d: true\n", i);
			else
			{
				if(res > c)
					printf("Case #%d: true\n", i);
				else
					printf("Case #%d: false\n", i);
			}
		}
		else if (a < 0 && b < 0)
		{
			if(res >= 0)
				printf("Case #%d: false\n", i);
			else
			{
				if (res > c)
					printf("Case #%d: true\n", i);
				else
					printf("Case #%d: false\n", i);
			}
		}
		else
		{
			if (res > c)
				printf("Case #%d: true\n", i);
			else
				printf("Case #%d: false\n", i);
		}
	}
	system("pause");
}