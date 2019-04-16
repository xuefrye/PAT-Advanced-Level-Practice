/*
1124 Raffle for Weibo Followers （20 分）
12分钟，无难度
*/
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

map<string, int> winner;


int main()
{
	string name; int m, n, s;
	int wcnt = 0;
	vector<string> list; list.push_back("0");//从1开始
	cin >> m >> n >> s;
	for (int i = 0; i < m; i++)
	{
		cin >> name;
		list.push_back(name);
	}

	for (int i = s; i < list.size();i+=n)
	{
		while (true) //注意这里的思想只要没有就继续，只要有就break；
		{
			if (winner[list[i]] == false)
			{
				winner[list[i]] = true;
				cout << list[i] << endl;
				wcnt++;
				break;
			}
			else
			{
				i++;
			}
			if (i >= list.size()) //防止无限循环
				break;
		}
	}

	if (wcnt == 0)
		printf("Keep going...\n");

}