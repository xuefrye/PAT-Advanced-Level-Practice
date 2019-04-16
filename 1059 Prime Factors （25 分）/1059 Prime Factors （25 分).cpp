/*1059 Prime Factors （25 分）
要点
1.制作素数表.无论你是什么方法,强行算还是筛选法
2.特殊情况特殊处理,当输入为1时直接输出1=1return
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring> // memset
const int maxn = 100000;
int prime[maxn]; //prime[i]是第i个素数.
int is_prime[maxn];
int prime_cnt = 0;
using namespace std;

void find_prime()
{
	memset(is_prime, 0xff, maxn);
	for (int i = 2;i < maxn;i++)
	{
		if (is_prime[i])
		{
			prime[++prime_cnt] = i;
			for (int j = 2*i ;j < maxn;j += i)
			{
				is_prime[j] = false;
			}
		}
	}
}

struct factor {
	int p; //质数
	int e = 0; //次数
}fac[10];

int main()
{
	find_prime();
	int result,input,cnt = 0;//cnt保存因数的个数.从0开始
	scanf("%d", &input);

	if (input == 1)
	{
		printf("1=1");
		return 0;
	}

	result = input;
	for (int i = 1; input > round(sqrt(result)); i++)
	{
		if (input % prime[i] == 0)
		{
			fac[cnt].p = prime[i];
			fac[cnt].e++;
			input /= prime[i]; //因为prime[i]是input的因数,所以一定能整除.
			while (input % prime[i] == 0)
			{
				fac[cnt].e++;
				input /= prime[i];
			}
			cnt++;
		}
	}

	if (input != 1) //说明还没被除尽
	{
		fac[cnt].p = input;
		fac[cnt].e = 1;
		cnt++;
		input = 1;
	}


	//以下是格式输出.
	printf("%d=", result);

	for (int i = 0;i < cnt - 1;i++)
	{
		if(fac[i].e != 1)
			printf("%d^%d*", fac[i].p, fac[i].e);
		else
			printf("%d*", fac[i].p);
	}
	//输出最后一项.
	if (fac[cnt-1].e != 1)
		printf("%d^%d", fac[cnt-1].p, fac[cnt-1].e);
	else
		printf("%d", fac[cnt-1].p);

	system("pause");
}