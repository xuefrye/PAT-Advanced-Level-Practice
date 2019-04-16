/*
1020 Tree Traversals （25 分）
注意点
1.总是把==写成=,心态炸裂.
20分钟就写完了,但是花了半小时找这个问题..虽然中途找到了一部分小毛病.
*/

#include <iostream>
#include <queue>
using namespace std;

int post[1000];
int in[1000];
bool first = true;

struct node
{
	int data;
	node* left;
	node* right;
};

node* create(int postL, int postR, int inL, int inR) //左闭右闭
{
	if (postL > postR)
		return NULL;

	node* root = new node;
	root->data = post[postR];

	int k;
	for (k = inL; k <= inR; k++)
	{
		if (in[k] == post[postR])
			break;
	}
	int leftcnt = k - inL;

	root->left = create(postL, postL + leftcnt - 1, inL, k - 1);
	root->right = create(postL + leftcnt, postR - 1, k + 1, inR);
	return root;
}

void leveltravel(node * root)
{
	if (root == NULL)
		return;

	queue<node *> qnode;
	qnode.push(root);

	while (!qnode.empty())
	{
		node* now = qnode.front();
		qnode.pop();
		if (first)
		{ 
			cout << now->data;
			first = false;
		}
		else
			cout << " " << now->data;
		if (now->left != NULL)
			qnode.push(now->left);
		if (now->right != NULL)
			qnode.push(now->right);
	}
}

int main()
{
	int n;
	cin >> n;

	if (n == 0)
		return 0;

	for (int i = 0; i < n; i++)
		cin >> post[i];

	for (int i = 0; i < n; i++)
		cin >> in[i];

	node* root = create(0,n-1,0,n-1);

	leveltravel(root);

	system("pause");
}