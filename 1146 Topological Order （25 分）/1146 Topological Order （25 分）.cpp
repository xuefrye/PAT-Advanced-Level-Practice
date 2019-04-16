/*
1146 Topological Order £¨25 ·Ö£©
*/
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1001;
struct node {
	int pre;
	int post;
	node(int a, int b)
	{
		pre = a;
		post = b;
	}
};

vector<int> adj[maxn];
int n, m, k;
vector<node> edge;
vector<int> ans;
vector<int> trueAns;

int findNum(vector<int> &v,int num)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == num)
			return i;
	}
	return -1;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int e1, e2;
		cin >> e1 >> e2;
		adj[e1].push_back(e2);
		edge.push_back(node(e1, e2));
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		ans.clear();
		for (int j = 0; j < n; j++)
		{
			int input; cin >> input;
			ans.push_back(input);
		}

		bool flag = true;
		for (int x = 0; x < edge.size(); x++)
		{
			if (findNum(ans, edge[x].pre) > findNum(ans, edge[x].post))
			{
				flag = false;
				break;
			}
		}

		if (!flag)
		{
			trueAns.push_back(i);
		}
	}

	bool first = true;
	for (int i = 0; i < trueAns.size(); i++)
	{
		if (first) 
		{ 
			printf("%d", trueAns[i]);
			first = false;
		}
		else printf(" %d", trueAns[i]);
	}
}