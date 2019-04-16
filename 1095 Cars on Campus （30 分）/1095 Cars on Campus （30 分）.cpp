#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct car
{
	string plate;
	int inTime;
	int outTime;
};

struct node
{
	string plate;
	int time;
	int flag;
};

bool cmp1(node &a, node&b)
{
	if (a.plate != b.plate)
		return a.plate < b.plate;
	else
		return a.time < b.time;
}

const int maxn = 1e4 + 10;
vector<node> record;
vector<car> ans;
int n, k,hour,miniute,second,t,inoutflag;
int ansTime = 0; vector<string> ansPlate;
string inout,plate;
unordered_map<string, int> plateTime;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> plate; 
		scanf("%d:%d:%d", &hour, &miniute, &second);
		t = hour * 3600 + miniute * 60 + second;
		cin >> inout;
		if (inout == "in") inoutflag = 1;
		else inoutflag = -1;
		record.push_back(node({ plate,t,inoutflag }));
	}

	sort(record.begin(), record.end(), cmp1);

	for (int i = 1; i < record.size(); i++)
	{
		if (record[i].plate == record[i - 1].plate && record[i].flag == -1 && record[i - 1].flag == 1)
			ans.push_back( car( { record[i].plate,record[i - 1].time,record[i].time } ) );
	}

	
	for (int i = 0; i < k; i++)
	{
		int cnt = 0;
		scanf("%d:%d:%d", &hour, &miniute, &second);
		t = hour * 3600 + miniute * 60 + second;
		for (int j = 0; j < ans.size(); j++)
		{
			if (ans[j].inTime <= t && ans[j].outTime >= t)
				cnt++;
		}
		printf("%d\n", cnt);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		plateTime[ans[i].plate] += ans[i].outTime - ans[i].inTime;
	}

	for (auto each:plateTime)
	{
		if (each.second > ansTime)
		{
			ansTime = each.second;
			ansPlate.clear();
			ansPlate.push_back(each.first);
		}
		else if (each.second == ansTime)
		{
			ansPlate.push_back(each.first);
		}
	}

	sort(ansPlate.begin(), ansPlate.end());

	for (int i = 0; i < ansPlate.size(); i++)
		printf("%s ", ansPlate[i].c_str());
	printf("%02d:%02d:%02d", ansTime / 3600, ansTime / 60 % 60, ansTime % 60);
	system("pause");
}