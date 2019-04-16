/*
1143 Lowest Common Ancestor £¨30 ·Ö£©
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
	node(int d, node*l=NULL, node* r=NULL) :data(d), left(l), right(r){}
};
const int maxn = 10100;
int m, n,u,v;
vector<int> pathu, pathv;

vector<int> pre(maxn);
vector<int> in(maxn);

node* build(int preL, int preR,int inL, int inR)
{
	if (inL > inR)
		return NULL;

	node* root = new node(pre[preL]);

	int pos;
	for (pos = inL; pos <= inR; pos++)
	{
		if (pre[preL] == in[pos])
			break;
	}

	int lenL = pos - inL;
	root->left = build(preL+1,preL+lenL,inL,pos-1);
	root->right = build(preL + lenL+1,preR,pos+1,inR);
	return root;
}

bool visited[maxn] = { false };
int father[maxn];
int findRoot(int i)
{
	while (father[i] != i)
	{
		i = father[i];
	}
	return i;
}
void tarjan(int root)
{


	
	{

	}
}

int find(node* root,int num, vector<int> &path)
{
	if (root == NULL)
		return -1;
	else if (root->data == num)
	{
		path.push_back(root->data);
		return root->data;
	}
	else if (num < root->data)
	{
		path.push_back(root->data);
		find(root->left, num, path);
	}
	else if (num >= root->data)
	{
		path.push_back(root->data);
		find(root->right, num, path);
	}
}


int main()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pre[i];
	}
	in = pre;
	sort(in.begin(), in.begin()+n);
	node* root = build(0, n - 1, 0, n - 1);

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		pathu.clear(); pathv.clear();
		int existu = find(root, u, pathu);
		int existv = find(root, v, pathv);

		if (existu == -1 && existv == -1)
		{
			printf("ERROR: %d and %d are not found.\n", u, v);
		}
		else if (existu == -1)
		{
			printf("ERROR: %d is not found.\n", u);
		}
		else if (existv == -1)
		{ 
			printf("ERROR: %d is not found.\n", v);
		}
		else
		{
			int x =0;
			while(x<pathu.size() && x<pathv.size() && pathu[x] == pathv[x])
				x++;

			int lca = pathu[x-1];
			if(lca != u && lca != v)
			{
				printf("LCA of %d and %d is %d.\n", u, v, lca);
			}
			else if (lca == u) {
				printf("%d is an ancestor of %d.\n", u, v);
			}
			else
			{
				printf("%d is an ancestor of %d.\n", v, u);
			}
		}
	}

	system("pause");
}