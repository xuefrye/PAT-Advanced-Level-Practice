/*
1135 Is It A Red-Black Tree £¨30 ·Ö£©
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1e6 + 10;
struct node
{
	int data;
	int color;
	node* left;
	node* right;
	node(int d, node* l=NULL, node* r=NULL)
	{
		data = d;
		left = l;
		right = r;
	}
};

bool cmp(int &a, int &b)
{
	return abs(a) < abs(b);
}

int k, n;
int pre[maxn];
int in[maxn];
int minDeep = 0x3fffffff;
int maxDeep = -1;
bool isRB = true;
int lastBcnt = -1;

node* build(int preL, int preR, int inL, int inR)
{
	if (preL > preR || inL > inR)
		return NULL;

	node* root = new node(abs(pre[preL]));
	if (pre[preL] < 0)
		root->color = -1;
	else
		root->color = +1;

	int pos;
	for (int i = inL; i <= inR; i++)
	{
		if(pre[preL] == in[i])
		{
			pos = i; break;
		}
	}

	int lenL = pos - inL;
	root->left = build(preL + 1, preL + lenL, inL, pos - 1);
	root->right = build(preL + lenL + 1, preR, pos + 1, inR);
	return root;
}

void dfs(node* root,int blackCnt)
{
	if (root == NULL)
	{

		if (lastBcnt == -1)
		{
			lastBcnt = blackCnt;
		}
		else
		{
			if (lastBcnt != blackCnt)
				isRB = false;
		}
		return;
	}
	if (root !=NULL && root->color == 1)
		blackCnt++;

	if (root != NULL && root->color == -1)
	{
		if (root->left != NULL)
			if(root->left->color == -1)
				isRB = false;
		if (root->right != NULL) 
			if(root->right->color == -1)
				isRB = false;
	}

	dfs(root->left,blackCnt);
	dfs(root->right,blackCnt);
}

void judge(node* root)
{
	minDeep = 0x3fffffff;
	maxDeep = -1;
	isRB = true;
	lastBcnt = -1;
	if(root ==NULL || root->color !=1)
	{
		printf("No\n"); return;
	}

	dfs(root, 0);

	if (isRB)
	{
		printf("Yes\n"); return;
	}
	else
	{
		printf("No\n"); return;
	}
}
int main()
{
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> pre[i];
			in[i] = pre[i];
		}
		sort(in, in + n,cmp);
		node *root = build(0, n - 1, 0, n - 1);
		judge(root);
	}
	system("pasue");
}