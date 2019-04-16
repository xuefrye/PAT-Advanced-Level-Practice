/*
1115 Counting Nodes in a BST £¨30 ·Ö£©
*/

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct node {
	int data;
	int height;
	int deep;
	node* left;
	node* right;
	node(int d,int dep=1,int h=1,node* l=NULL,node* r=NULL):data(d),deep(dep),height(h),left(l),right(r){}
};


int n, d, n1 = 0, n2 = 0;
vector<node> ans;
int getHeight(node* root)
{
	if (root == NULL)
		return 0;
	else
		return root->height;
}

void updateHeight(node* root)
{
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
}

void insert(node* &root, int data)
{
	if (root == NULL)
	{
		root = new node(data); return;
	}

	if (data <= root->data)
	{
		insert(root->left, data);
		updateHeight(root);
	}
	else
	{
		insert(root->right, data);
		updateHeight(root);
	}
}

void dfs(node* root)
{
	if (root == NULL)
		return;

	if (root->height == 1)
		n1++;
	if (root->height == 2)
		n2++;

	dfs(root->left);
	dfs(root->right);
}


void bfs(node* root)
{
	queue<node> qnode;
	node temp = *root; temp.deep = 1;
	qnode.push(temp);

	while (!qnode.empty())
	{
		temp = qnode.front(); qnode.pop();
		ans.push_back(temp);
		if (temp.left != NULL)
		{
			qnode.push(node(temp.left->data, temp.deep + 1, 0, temp.left->left, temp.left->right));
		}
		if (temp.right != NULL)
		{
			qnode.push(node(temp.right->data, temp.deep + 1, 0, temp.right->left, temp.right->right));
		}
	}
}

int main()
{
	node* root = NULL;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d;
		insert(root, d);
	}

	bfs(root);

	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i].deep == ans[0].deep)
			n1++;
		if (ans[i].deep == ans[0].deep - 1)
			n2++;
	}
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
	system("pause");
}