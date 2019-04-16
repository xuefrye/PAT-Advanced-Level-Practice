/*
1064 Complete Binary Search Tree £®30 ∑÷£©
¥ÀÃ‚¥ÌŒÛ
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
const int maxn = 1001;
int input[maxn];
int n;

struct node
{
	int data;
	node* left;
	node* right;
	node(int d, node* l = NULL, node* r= NULL) :data(d), left(l), right(r) {}
};

node* build(int L, int R)
{
	if (L > R)
		return NULL;
	//int M = (int)ceil((L + R) / 2.0);
	int M = ceil((R+L) / 2.0);
	node* root = new node(input[M]);

	root->left = build(L,M-1);
	root->right = build(M+1,R);
	return root;
}

void level(node* root)
{
	if (root == NULL)
		return;

	queue<node*> qnode;
	qnode.push(root);
	while (!qnode.empty())
	{
		node* temp = qnode.front(); qnode.pop();
		printf("%d ", temp->data);
		if (temp->left != NULL)
			qnode.push(temp->left);
		if (temp->right != NULL)
			qnode.push(temp->right);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	sort(input, input + n);

	node* root = build(0, n-1);
	level(root);
	system("pause");
}
