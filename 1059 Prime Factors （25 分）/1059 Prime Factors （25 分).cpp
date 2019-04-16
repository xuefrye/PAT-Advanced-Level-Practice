/*1059 Prime Factors ��25 �֣�
Ҫ��
1.����������.��������ʲô����,ǿ���㻹��ɸѡ��
2.����������⴦��,������Ϊ1ʱֱ�����1=1return
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstring> // memset
const int maxn = 100000;
int prime[maxn]; //prime[i]�ǵ�i������.
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
	int p; //����
	int e = 0; //����
}fac[10];

int main()
{
	find_prime();
	int result,input,cnt = 0;//cnt���������ĸ���.��0��ʼ
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
			input /= prime[i]; //��Ϊprime[i]��input������,����һ��������.
			while (input % prime[i] == 0)
			{
				fac[cnt].e++;
				input /= prime[i];
			}
			cnt++;
		}
	}

	if (input != 1) //˵����û������
	{
		fac[cnt].p = input;
		fac[cnt].e = 1;
		cnt++;
		input = 1;
	}


	//�����Ǹ�ʽ���.
	printf("%d=", result);

	for (int i = 0;i < cnt - 1;i++)
	{
		if(fac[i].e != 1)
			printf("%d^%d*", fac[i].p, fac[i].e);
		else
			printf("%d*", fac[i].p);
	}
	//������һ��.
	if (fac[cnt-1].e != 1)
		printf("%d^%d", fac[cnt-1].p, fac[cnt-1].e);
	else
		printf("%d", fac[cnt-1].p);

	system("pause");
}