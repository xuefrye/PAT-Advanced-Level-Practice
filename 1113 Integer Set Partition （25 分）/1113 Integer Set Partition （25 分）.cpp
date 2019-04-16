/*
1113 Integer Set Partition £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int num[maxn];
int s1=0, s2=0,sum=0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
	}
	sort(num, num + n);

	for (int i = 0; i < n / 2; i++)
		s1 += num[i];

	s2 = sum - s1;
	if (n % 2 == 0)
		printf("%d ", 0);
	else printf("%d ", 1);
	printf("%d", abs(abs(s1) - abs(s2)));
	system("pause");

}