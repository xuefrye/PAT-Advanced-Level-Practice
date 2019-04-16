#include<iostream>
#include<map>
#include<string>

using namespace std;

const int maxn = 2000;
int numPerson=0;
map<string, int> name2int;
map<int, string>  int2name;
int n, k;
string name1, name2;
int id1, id2, w;
int G[maxn][maxn] = { 0 }; //边权表
int node[maxn] = { 0 }; //点权表
bool visited[maxn] = { false };
map<string, int> gangs;

int change(string &name)
{
	if (name2int.find(name) != name2int.end())
	{
		return name2int[name];
	}
	else
	{
		name2int[name] = numPerson;
		int2name[numPerson] = name;
		return numPerson++;
	}
}

void dfs(int id, int &head, int &sumWeight,int &sumPerson)
{
	visited[id] = true;

	if (node[id] > node[head])
	{
		head = id;
	}

	for (int i = 0; i < numPerson; i++)
	{
		if (G[id][i] > 0)
		{
			sumWeight += G[id][i];
			G[id][i] = 0;
			G[i][id] = 0;
			if (visited[i] == false);
				dfs(i, head, sumWeight, ++sumPerson);
		}
	}
	
}

void travel()
{
	int head=0, sumWeight=0, sumPerson=0;
	for (int id = 0; id < numPerson; id++)
	{
		if (visited[id] == false)
		{
			sumWeight = 0;
			sumPerson = 0;
			head = id;
			dfs(id, head, sumWeight, ++sumPerson);
			if (sumWeight > k && sumPerson > 2)
			{
				gangs[int2name[head]] = sumPerson;
			}
		}
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> name1 >> name2 >> w;
		id1 = change(name1);
		id2 = change(name2);
		node[id1] += w;
		node[id2] += w;
		G[id1][id2] += w;
		G[id2][id1] += w;
	}

	travel();

	cout << gangs.size() << endl;


	for (auto it = gangs.begin(); it != gangs.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	system("pause");
}