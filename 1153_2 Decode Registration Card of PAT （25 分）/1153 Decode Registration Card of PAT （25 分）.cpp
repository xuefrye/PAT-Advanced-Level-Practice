#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct stu
{
	string id;
	int score;
};

struct node
{
	string site;
	int cnt;
	node(string s, int c)
	{
		site = s;
		cnt = c;
	}
};
vector<node> ans;
bool compare1(node &a, node &b)
{
	if (a.cnt != b.cnt)
		return a.cnt > b.cnt;
	else
		return a.site < b.site;
}


bool compare(stu &a, stu &b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.id < b.id;
}

int n, m, type;
string term;
unordered_map<string, int> ans3;
int main()
{
	freopen("1153.txt", "r", stdin);
	cin >> n >> m;
	vector<stu> stus(n);
	for (int i = 0; i < n; i++)
	{
		cin >> stus[i].id;
		cin >> stus[i].score;
	}
	for (int i = 1; i <= m; i++)
	{
		int has = false;
		cin >> type >> term;
		printf("Case %d: %d %s\n", i, type, term.c_str());
		if (type == 1)
		{
			sort(stus.begin(), stus.end(), compare);
			for (auto each : stus)
			{
				if (each.id.substr(0, 1) == term)
				{
					printf("%s %d\n", each.id.c_str(), each.score);
					has = true;
				}
			}
		}
		else if (type == 2)
		{
			int sum = 0, cnt = 0;
			for (auto &each : stus)
			{
				if (each.id.substr(1, 3) == term)
				{
					sum += each.score;
					cnt++;
					has = true;
				}
			}
			if (has)
				printf("%d %d\n", cnt, sum);
		}
		else if (type == 3)
		{
			int cnt3 = 0;
			ans3.clear();
			ans.clear();
			for (auto &each : stus)
			{
				if (each.id.substr(4, 6) == term)
				{
					ans3[each.id.substr(1, 3)]++;
				}
			}
			for (auto &each : ans3)
			{
				ans.push_back(node(each.first, each.second));
			}
			sort(ans.begin(), ans.end(), compare1);
			for (auto &each : ans)
			{
				has = true;
				printf("%s %d\n", each.site.c_str(), each.cnt);
			}
		}
		if (has == false)
			printf("NA\n");
	}
}