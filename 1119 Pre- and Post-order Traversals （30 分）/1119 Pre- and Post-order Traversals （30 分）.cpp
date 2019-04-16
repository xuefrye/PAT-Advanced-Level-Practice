/*
1119 Pre- and Post-order Traversals £¨30 ·Ö£©
*/
#include<iostream>
using namespace std;
const int maxn = 100;
int n;
int pre[maxn], post[maxn];
bool flag = true;
bool first = true;

struct node {
	int data;
	node* left;
	node* right;
	node(int d,node* l=NULL,node* r=NULL):data(d),left(l),right(r){}
};
node* build(int preL, int preR, int postL, int postR)
{
	if (preL > preR || postL > postR)
		return NULL;
	if (preL == preR)
	{
		node* root = new node(pre[preL]);
		return new node(pre[preL]);
	}
	if (postL == postR)
	{
		node* root = new node(post[postL]);
		return new node(post[postL]);
	}

	node* root = new node(pre[preL]);

	if (pre[preL + 1] == post[postR - 1])
	{
		flag = false;
		root->left = build(preL + 1, preR, postL, postR - 1);
		root->right = NULL;
	}
	else
	{
		int preLroot = preL + 1;
		int pos;
		for(int i=postL;i<=postR;i++)
			if (pre[preLroot] == post[i])
			{
				pos = i;
				break;
			}

		int lenL = pos - postL + 1;

		root->left = build(preL + 1, preL + lenL, postL, pos);
		root->right = build(preL + lenL + 1, preR, pos + 1, postR - 1);
	}
	return root;
}

void inOrder(node* root)
{
	if (root == NULL) return;

	inOrder(root->left);
	if (first)
	{
		printf("%d", root->data); first = false;
	}
	else
		printf(" %d", root->data);
	inOrder(root->right);
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pre[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> post[i];
	}
	flag = true; first = true;

	node* root = build(0, n - 1, 0, n - 1);
	
	printf("%s\n",  flag ? "Yes" : "No");
	
	inOrder(root);
	printf("\n");
	system("pause");
}