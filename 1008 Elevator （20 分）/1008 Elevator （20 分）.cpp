/*
1008 Elevator £¨20 ·Ö£©
*/

#include<iostream>
using namespace std;
int n, now=0,f;
int s=0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> f;
		if (now < f)
		{
			while (now != f)
			{
				now++;
				s += 6;
			}
			
		}
		else if (now > f)
		{
			while (now != f)
			{
				now--;
				s += 4;
			}
			
		}
		s += 5;
	}
	printf("%d\n", s);
}