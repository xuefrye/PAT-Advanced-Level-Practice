/*
1125 Chain the Ropes £¨25 ·Ö£©
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, in;
vector<int> ans;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		ans.push_back(in);
	}
	sort(ans.begin(), ans.end());
	for (int i = 1; i < ans.size(); i++)
	{
		ans[i] = (ans[i] + ans[i - 1]) / 2;
	}

	printf("%d", ans[ans.size() - 1]);
	system("pause");
}