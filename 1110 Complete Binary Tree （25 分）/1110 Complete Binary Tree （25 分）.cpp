/*
1110 Complete Binary Tree £¨25 ·Ö£©
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 10000000;
struct node {
	int id;
	int left;
	int right;
}tree[maxn];

int n;
string l, r;
bool visited[maxn] = { false };
bool exist[maxn] = { false };
vector<int> d;
int ctree[maxn];
int lastid,predeep=0,preid=0;

void build(int root,int idx)
{
	ctree[idx] = root;
	if (tree[root].left != -1)
		build(tree[root].left, idx * 2);
	if (tree[root].right != -1)
		build(tree[root].right, idx * 2+1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l >> r;
		if (l != "-")
		{
			tree[i].left = stoi(l);
			exist[stoi(l)] = true;
		}
		else
			tree[i].left = -1;
		if (r != "-")
		{
			tree[i].right = stoi(r);
			exist[stoi(r)] = true;
		}
		else
			tree[i].right = -1;
	}
	int root;
	for (int i = 0; i < n; i++)
	{
		if (exist[i] == false)
		{
			root = i;
			break;
		}
	}
	fill(ctree, ctree + maxn, -1);
	build(root, 1);

	for (int i = 1; i <= n; i++)
	{
		if (ctree[i] == -1)
		{
			printf("NO %d", root);
			system("pause");  return 0;
		}
	}

	printf("YES %d", ctree[n]);
	system("pause");  return 0;
}

/*
9
- -
- -
- -
- -
0 1
2 3
4 5
- -
- -
*/