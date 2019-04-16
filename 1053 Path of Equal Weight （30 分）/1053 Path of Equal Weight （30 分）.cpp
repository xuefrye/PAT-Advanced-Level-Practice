/*
1053 Path of Equal Weight （30 分）
非空树根节点R
每个节点T都有权重W
总权重是根节点R到叶子节点L路径中节点权重之和.
找出与给出权重相同的路径.
nodeID两位数
weight 是 int
n是节点个数<=100
m是非叶子节点
s给出的权重
n个数wi是权重
m行

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;

struct node{
	int id;
	int weight;
	int k=0;
	vector<int> child;
	node(){}
	node(int i, int w,int k)
	{
		id = i;
		weight = w;
	}
}nodes[maxn];

//bool compare(node &a, node &b)
//{
//	return a.id < b.id;
//}

bool compare1(int &a, int &b)
{
	if (nodes[a].weight != nodes[b].weight)
		return nodes[a].weight > nodes[b].weight;
	else return nodes[a].id > nodes[b].id;
}

int n, m, givenw, w, id, nchild, childid;
bool first = true;
vector<node> temp, ans;

void dfs(int root,int sum) //这个节点和这个节点带来的权重总和
{
	if (nodes[root].k == 0 || sum >= givenw) //返回条件 没有孩子||总和>=
	{
		if (nodes[root].k == 0 && sum == givenw)//到达末尾&&总和为givenw更新结果并打印
		{ 
			ans = temp; 
			//sort(ans.begin(), ans.end(), compare);
			for (auto each : ans)
			{
				if (first)
				{ 
					printf("%d", each.weight);
					first = false;
				}
				else
				{
					printf(" %d", each.weight);
				}
			}
			first = true;
			printf("\n");
		}
		return;
	}

	for (int i = 0; i < nodes[root].k; i++)
	{
		temp.push_back(nodes[nodes[root].child[i]]); //将节点root的第i个孩子加入
		dfs(nodes[root].child[i], sum + nodes[nodes[root].child[i]].weight);
		temp.pop_back();
	}

}

int main()
{
	cin >> n >> m >> givenw;
	for (int i = 0; i < n; i++)
	{
		cin >> w;
		nodes[i].weight = w;
		nodes[i].id = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> id >> nchild;
		nodes[id].k = nchild;
		for (int j = 0; j < nchild; j++)
		{
			cin >> childid;
			nodes[id].child.push_back(childid);
		}
		sort(nodes[id].child.begin(), nodes[id].child.end(), compare1); //孩子从大到小排序.
	}

	temp.push_back(nodes[0]);
	dfs(00, nodes[0].weight);

	system("pause");
}
