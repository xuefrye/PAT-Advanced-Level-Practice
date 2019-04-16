/*
1120 Friend Numbers £¨20 ·Ö£©
*/
#include<iostream>
#include<set>
#include<vector>
using namespace std;

set<int> fid;
vector<int> in;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num,tempid = 0;;
		cin >> num;

		while (num != 0)
		{
			tempid += num % 10;
			num /= 10;
		}
		fid.insert(tempid);
	}

	printf("%d\n", fid.size());
	bool first=true;
	for (auto each : fid)
	{
		if (first)
		{
			printf("%d", each);
			first = false;
		}
		else
			printf(" %d", each);
	}
}