/*
1053 Path of Equal Weight ��30 �֣�
�ǿ������ڵ�R
ÿ���ڵ�T����Ȩ��W
��Ȩ���Ǹ��ڵ�R��Ҷ�ӽڵ�L·���нڵ�Ȩ��֮��.
�ҳ������Ȩ����ͬ��·��.
nodeID��λ��
weight �� int
n�ǽڵ����<=100
m�Ƿ�Ҷ�ӽڵ�
s������Ȩ��
n����wi��Ȩ��
m��

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

void dfs(int root,int sum) //����ڵ������ڵ������Ȩ���ܺ�
{
	if (nodes[root].k == 0 || sum >= givenw) //�������� û�к���||�ܺ�>=
	{
		if (nodes[root].k == 0 && sum == givenw)//����ĩβ&&�ܺ�Ϊgivenw���½������ӡ
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
		temp.push_back(nodes[nodes[root].child[i]]); //���ڵ�root�ĵ�i�����Ӽ���
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
		sort(nodes[id].child.begin(), nodes[id].child.end(), compare1); //���ӴӴ�С����.
	}

	temp.push_back(nodes[0]);
	dfs(00, nodes[0].weight);

	system("pause");
}
