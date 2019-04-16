/*
1108 Finding Average £¨20 ·Ö£©
*/
#include<iostream>
#include<string>

using namespace std;

bool judge(string str)
{
	int i = 0,dot=0,frac =0;
	if (str[0] == '-')
	{
		i++;
	}
	for (; i < str.size(); i++)
	{
		if (str[i] == '.')
		{
			dot++;
			if (dot >= 2)
				return false;
		}
		else if (str[i] <= '9' && str[i] >= '0')
		{
			if (dot)
			{
				frac++;
				if (frac > 2)
					return false;
			}
		}
		else	
			return false;
	}

	if(stod(str)<=1000 && stod(str) >=-1000)
		return true;
	else
		return false;
}

int main()
{
	int n, cnt = 0;double sum = 0;
	string in;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		if (judge(in))
		{
			cnt++;
			sum += stod(in);
		}
		else
		{
			printf("ERROR: %s is not a legal number\n", in.c_str());
		}
	}
	if (cnt == 1)
	{
		printf("The average of 1 number is %.2f\n", sum);
	}
	else if (cnt)
		printf("The average of %d numbers is %.2f\n", cnt, (double)sum / cnt);
	else
		printf("The average of 0 numbers is Undefined");

}
