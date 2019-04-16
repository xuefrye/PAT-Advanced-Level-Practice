/*
1104 Sum of Number Segments £¨20 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

const int maxn = 1e5 + 1;
double seq[maxn];
long long weight[maxn];
long long n;
double sum=0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n / 2.0; i++)
		weight[i] = weight[n - i-1] = (n - i)*(i + 1);
	
	for (int i = 0; i < n; i++)
		scanf("%lf", &seq[i]);

	for (int i = 0; i < n; i++)
		sum += seq[i] * weight[i];
	printf("%.2f\n", sum);
}
