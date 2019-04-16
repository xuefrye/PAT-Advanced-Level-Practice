/*
1034 Head of a Gang £¨30 ·Ö£©
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct edge
{
	int time;
	string id;
	set<string> name;
};

struct gangmenber
{
	string name;
	int time;
	gangmenber(string n, int t) :name(n), time(t){}
};

//struct node
//{
//	string name;
//	int time;
//}G[maxn];

map<string, edge> G;
map<string, bool> visited;

const int maxn = 1010;
vector<edge> Adj[maxn];
vector<gangmenber> gang;
int sum=0;
string head;
int n, k, time;


int dfs(string id)
{
	visited[id] = true;
	gang.push_back(gangmenber(id, G[id].time));
	for (auto it = G[id].name.begin(); it != G[id].name.end(); it++)
		if (visited[*it] == false)
		{ 
			sum += G[*it].time;
			dfs(*it);
		}
	return sum;
}

bool compare(gangmenber &a, gangmenber& b)
{
	return a.time > b.time;
}
int dfsG()
{
	int cnt = 0;
	for (auto it = G.begin(); it != G.end(); it++)
	{
		if (visited[it->first] == false)
		{
			if (dfs(it->first) > k)
			{ 
				sort(gang.begin(), gang.end(), compare);
				cout << gang[0].name << " " << gang.size();
				gang.clear();
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	gang.clear();
	string name1, name2;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> name1 >> name2 >> time;
		visited[name1] = visited[name2] = false;
		G[name1].id = name1;
		G[name2].id = name2;
		G[name1].time += time;
		G[name1].name.insert(name2);
		G[name2].time += time;
		G[name2].name.insert(name1);
	}

	cout << dfsG();
	system("pause");
}

