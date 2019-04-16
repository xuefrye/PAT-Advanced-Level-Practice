/*
1085 Perfect Sequence £¨25 ·Ö£©
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long n,p,a,b,max1,max2;
int main()
{
	cin >> n >> p;
	
	vector<long long> seq(n);
	for (int i = 0; i < n; i++)
		cin >> seq[i];
	sort(seq.begin(), seq.end());

	int temp, ans;
	for(int i=0;i<n;i++)
		for (int j = i+ans; j < n; j++)
		{
			if (seq[i] * p >= seq[j])
			{
				temp = j - i + 1;
				if (ans < temp)
					ans = temp;
			}
			else
				break;
		}
	printf("%d\n", ans);



	/*a = 0; b = n - 1;

	for (int i = 0; i < n; i++)
	{
		if (seq[i] * p >= seq[n-1])
		{
			a = i; break;
		}
	}
	max1 = b - a + 1;
	a = 0; b = n - 1;
	for (int i = n-1; i >=0; i--)
	{
		if (seq[0] * p >= seq[i])
		{
			b = i; break;
		}
	}
	max2 = b - a + 1;
	printf("%d\n", max(max1,max2));*/
}

/*
10 2
2 3 20 4 5 1 6 7 8 9
*/