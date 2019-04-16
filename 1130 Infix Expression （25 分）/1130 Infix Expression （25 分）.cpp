/*
1130 Infix Expression £¨25 ·Ö£©
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int maxn = 30;
int n;
bool notRoot[maxn] = { false };
struct node
{
	string data;
	int left;
	int right;
}nodes[maxn];
int root;


void dfs(int id)
{
	if (nodes[id].left == -1 && nodes[id].right == -1)
		return;
	else
	if (nodes[id].left != -1 && nodes[id].right == -1 && nodes[nodes[id].left].left == -1 && nodes[nodes[id].left].right == -1)
	{
		nodes[id].data = "("+nodes[id].data + nodes[nodes[id].left].data+")";
		nodes[id].left = -1;
		return;
	}
	else if (nodes[id].left == -1 && nodes[id].right != -1 && nodes[nodes[id].right].left == -1 && nodes[nodes[id].right].right == -1)
	{
		nodes[id].data = "(" + nodes[id].data + nodes[nodes[id].right].data + ")";
		nodes[id].right = -1;
		return;
	}
	else if (nodes[id].left != -1 && nodes[id].right != -1
		&& nodes[nodes[id].left].left == -1 && nodes[nodes[id].left].right == -1
		&& nodes[nodes[id].right].left == -1 && nodes[nodes[id].right].right == -1)
	{
		nodes[id].data = "(" + nodes[nodes[id].left].data + nodes[id].data + nodes[nodes[id].right].data + ")";
		nodes[id].left = -1;
		nodes[id].right = -1;
		return;
	}

	//dfs(nodes[id].left);
	//dfs(nodes[id].right);
}


string dfs2(int id)
{
	if (nodes[id].left == -1 && nodes[id].right == -1)
	{
		return nodes[id].data;
	}
	else if(nodes[id].left != -1 && nodes[id].right != -1)
	{
		return "(" + dfs2(nodes[id].left) + nodes[id].data + dfs2(nodes[id].right) + ")";
	}
	else if (nodes[id].left == -1 && nodes[id].right != -1)
	{
		return "(" + nodes[id].data + dfs2(nodes[id].right) + ")";
	}
}

void travel()
{
	while (nodes[root].left != -1 || nodes[root].right != -1)
	{
		for (int i = 1; i <= n; i++)
			dfs(i);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nodes[i].data >> nodes[i].left >> nodes[i].right;
		if (nodes[i].left != -1)
		{
			notRoot[nodes[i].left] = true;
		}
		if (nodes[i].right != -1)
		{
			notRoot[nodes[i].right] = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (notRoot[i] == false)
		{
			root = i;
			break;
		}
	}
	//travel();
	//if (nodes[root].data[0] == '(')
	//	cout << nodes[root].data.substr(1, nodes[root].data.size() - 2);
	//else
	//	cout << nodes[root].data;
	string ans = dfs2(root);
	if(ans[0] =='(')
		cout << ans.substr(1, ans.size()-2);
	else
		cout << ans;
	
	system("pause");
}