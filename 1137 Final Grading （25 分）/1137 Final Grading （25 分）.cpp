/*
1137 Final Grading £¨25 ·Ö£©
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct stu
{
	string name;
	int oScore;
	int mScore;
	int fScore;
	int score;
	stu(string n="", int o=-1, int m = -1, int f = -1, int s = -1)
	{
		name = n;
		oScore = o;
		mScore = m;
		fScore = f;
		score = s;
	}
};

bool cmp(stu &a, stu &b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.name < b.name;
}

int p, m, n;
string id; int score;
vector<stu> ans;
map<string, stu> stus;

int main()
{
	cin >> p >> m >> n;
	for (int i = 0; i < p; i++)
	{
		cin >> id >> score;
		stus[id].oScore = score;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> id >> score;
		stus[id].mScore = score;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> id >> score;
		stus[id].fScore = score;
	}

	for (auto &each : stus)
	{
		if (each.second.oScore >= 200)
		{
			if (each.second.mScore > each.second.fScore)
				each.second.score = int(0.4 * each.second.mScore + 0.6 * each.second.fScore + 0.5); 
			else
			{
				each.second.score = each.second.fScore;
			}
		}

		if (each.second.score >=60)
		{
			ans.push_back(stu(each.first, each.second.oScore, each.second.mScore, each.second.fScore, each.second.score));
		}
	}

	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++)
		printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].oScore, ans[i].mScore, ans[i].fScore, ans[i].score);
	//system("pause");
}