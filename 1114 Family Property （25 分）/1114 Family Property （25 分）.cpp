/*
1114 Family Property £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>
using namespace std;

struct ansNode
{
	int minid, memberCnt;
	double avgSet, avgArea;
};

const int maxn = 100100;
int n, id, fid, mid, k, cid, M, Area;

int m[maxn] = { 0 };
int area[maxn] = { 0 };
vector<int> adj[maxn];
bool visited[maxn] = { false };
unordered_set<int> totalMember;
char output[10000];
vector<ansNode> ans;

bool cmp(ansNode &a, ansNode &b)
{
	if (a.avgArea != b.avgArea)
		return a.avgArea > b.avgArea;
	else
		return a.minid < b.minid;
}

void dfs(int id, int &minid, int &memberCnt, int &totalSet, int &totalArea)
{
	visited[id] = true;
	if (id < minid) minid = id; 
	memberCnt++; totalSet += m[id]; totalArea += area[id];

	for (int i = 0; i < adj[id].size(); i++)
	{
		if(visited[adj[id][i]]==false)
			dfs(adj[id][i], minid, memberCnt, totalSet, totalArea);
	}
}

void travel()
{
	int familyCnt = 0;
	for (auto id:totalMember)
	{
		int minid=10000, memberCnt=0,totalSet=0, totalArea=0;
		double avgSet, avgArea;
		if (visited[id] == false)
		{
			dfs(id, minid, memberCnt, totalSet, totalArea);
			avgSet = totalSet / (double)memberCnt;
			avgArea = totalArea / (double)memberCnt;
			ans.push_back(ansNode({ minid, memberCnt, avgSet, avgArea }));
			familyCnt++;
		}
	}
	cout << familyCnt << endl;
	sort(ans.begin(), ans.end(), cmp);
	for (auto each : ans)
	{
		printf("%04d %d %.3lf %.3lf\n", each.minid, each.memberCnt, each.avgSet, each.avgArea);
	}
}
int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &id, &fid, &mid);
		
		totalMember.insert(id);
		if (fid != -1) adj[id].push_back(fid); 
		if (mid != -1) adj[id].push_back(mid);

		if (fid != -1) totalMember.insert(fid);
		if (fid != -1) adj[fid].push_back(id); 
		if (fid != -1 && mid !=-1) adj[fid].push_back(mid);

		if (mid != -1) totalMember.insert(mid);
		if (fid != -1 && mid != -1) adj[mid].push_back(fid);
		if (mid != -1) adj[mid].push_back(id);


		scanf("%d", &k);
		for(int j=0;j<k;j++)
		{
			scanf("%d", &cid);
			adj[id].push_back(cid);
			adj[cid].push_back(id);
			totalMember.insert(cid);
		}
		scanf("%d %d", &M, &Area);
		m[id] = M;
		area[id] = Area;
	}

	travel();
	system("pasue");
}