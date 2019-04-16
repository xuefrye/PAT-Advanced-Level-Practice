/*
1141 PAT Ranking of Institutions （25 分）
迷糊状态下37分钟完成
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct node
{
	string name;
	int number = 0;
	int bScore = 0;
	int aScore = 0;
	int tScore = 0;
	int sum =0;
	int rank;
	node(){}
	node(string a, int b, int c)
	{
		name = a;
		number = b;
		sum = c;
	}
};


bool cmp(node &a, node &b)
{
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.number != b.number)
		return a.number < b.number;
	else
		return a.name < b.name;
}

string a;
map<string, node> school;
int n;
string id; int score; char sname[50];
string schoolName;
vector<node> ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> id >> score;  scanf("%s", sname);
		for (int i = 0; i < strlen(sname); i++)
		{
			sname[i] = tolower(sname[i]);
		}
		schoolName = sname;
		
		school[schoolName].name = schoolName;
		school[schoolName].number++;
		if (id[0] == 'A')
			school[schoolName].aScore += score;
		else if (id[0] == 'B')
			school[schoolName].bScore += score;
		else if (id[0] == 'T')
				school[schoolName].tScore += score;
	}
	for (auto each : school)
	{
		int totalScore = each.second.bScore / 1.5 + each.second.aScore + each.second.tScore*1.5;
		ans.push_back(node(each.first, each.second.number, totalScore));
	}

	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++)
	{
		if (i == 0)
		{
			ans[i].rank = 1;
		}
		else
		{
			if (ans[i].sum == ans[i - 1].sum)
				ans[i].rank = ans[i - 1].rank;
			else
				ans[i].rank = i + 1;
		}
	}

	printf("%d\n", school.size());
	for (auto each : ans)
	{
		printf("%d %s %d %d\n", each.rank, each.name.c_str(), each.sum, each.number);
	}
	system("pause");
}