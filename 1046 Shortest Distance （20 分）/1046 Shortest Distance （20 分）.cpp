/*
1046 Shortest Distance £¨20 ·Ö£©

*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int n1,n2,a,b,dis1,dis2;
int dis[100010];
int sum = 0;
inline void swap1(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	scanf("%d", &n1);
	for (int i = 1; i <= n1; i++)
	{
		scanf("%d", &dis[i]);
		sum += dis[i];
	}	

	scanf("%d", &n2);
	for (int i = 0; i < n2; i++)
	{
		dis1 = dis2 = 0;
		scanf("%d %d", &a, &b);
		if (a > b)
			swap1(a, b);
		else if (a == b)
		{
			printf("0\n");
			continue;
		}
		for (int j = a; j != b; j++)
			dis1 += dis[j];

		dis2 = sum - dis1;
		if(dis1<dis2)
			printf("%d\n", dis1);
		else
			printf("%d\n", dis2);
	}


	system("pause");
}