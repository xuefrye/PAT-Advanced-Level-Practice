/*
1011 World Cup Betting £¨20 ·Ö£©
*/

#include<iostream>
using namespace std;
int a, b, c;
double max1 = 0, now; int idx;
double ans = 1;
int main()
{
	for (int i = 0; i < 3; i++)
	{
		max1 = 0,idx=0;
		for (int j = 0; j < 3; j++)
		{
			cin >> now;
			if (now > max1)
			{
				max1 = now;
				idx = j;
			}
		}
		if (idx == 0) printf("W ");
		else if (idx == 1) printf("T ");
		else if (idx == 2) printf("L ");
		ans *= max1;
	}
	ans = (ans*0.65 - 1) * 2;
	printf("%.2lf", ans);
}