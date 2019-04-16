/*
1043 Is It a Binary Search Tree （25 分）
2019年2月11日00:41:00
半小时写完却没有注意镜像树输出.
注意点
1.如果是镜像树就要用镜像树的post遍历...就是这个点出了问题
2.create这个函数还是没记住.继续加强
*/

#include<iostream>
#include<vector>
using namespace std;
vector<int> inputv, preoder, premorder;
bool first = true;

struct node
{
	int data;
	node* left;
	node* right;
	node(){}
	node(int d, node*l = NULL, node* r = NULL)
	{
		data = d;
		left = l;
		right = r;
	}
};

void insert(node *&root,int data)
{
	if (root == NULL)
	{ 
		root = new node(data);
		return;
	}

	if (data >= root->data)
		insert(root->right, data);
	else
		insert(root->left, data);
}

node* create(int a[],int len)
{
	node* root = NULL;
	for (int i = 0; i < len; i++)
	{
		insert(root, a[i]);
	}
	return root;
}

void pre(node* root)
{
	if (root == NULL)
		return;
	preoder.push_back(root->data);
	//printf("%d ", root->data);
	pre(root->left);
	pre(root->right);
}

void prem(node* root)
{
	if (root == NULL)
		return;
	premorder.push_back(root->data);
	//printf("%d ", root->data);
	prem(root->right);
	prem(root->left);
}

void post(node* root)
{
	if (root == NULL)
		return;
	post(root->left);
	post(root->right);
	if (first)
	{
		printf("%d", root->data);
		first = false;
	}
	else
		printf(" %d", root->data);
}

void postm(node* root)
{
	if (root == NULL)
		return;
	postm(root->right);
	postm(root->left);
	if (first)
	{
		printf("%d", root->data);
		first = false;
	}
	else
		printf(" %d", root->data);
}

int main()
{
	const int maxn = 1010;
	int n;
	int input[maxn];
	int temp;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		inputv.push_back(input[i]);
	}

	node *root = create(input, n);

	pre(root);
	prem(root);

	if (inputv == preoder)
	{
		printf("YES\n");
		post(root);
	}
	else if (inputv == premorder)
	{
		printf("YES\n");
		postm(root);
	}
	else
		printf("NO");
	system("pause");
}