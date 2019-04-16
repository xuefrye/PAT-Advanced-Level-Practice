/*
1148 Werewolf - Simple Version £¨20 ·Ö£©
*/
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1000;

int n;

int main()
{
	cin >> n;
	vector<int> input(n+1);

	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			vector<int> ans(n + 1, 1);
			vector<int> lie;
			ans[j] = ans[i] = -1;
			for (int k = 1; k <= n; k++)
			{
				if (input[k] * ans[abs(input[k])] < 0)
					lie.push_back(k);
			}
			if (lie.size() == 2 && ans[lie[1]] + ans[lie[0]] == 0)
			{ 
				cout << i << " " << j;
				return 0;
			}
		}
	}
	cout << "No Solution";
	system("pause");

}