/*
1086 Tree Traversals Again （25 分）
注意点.
1.一开始没写递归基.
*/

#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

vector<int> in;
vector<int> pre;
stack<int> input;
string p;
bool first = true;

struct node
{
	int data;
	node* left;
	node* right;
	node(int d, node* l=NULL, node* r=NULL)
	{
		data = d;
		left = l;
		right = r;
	}
};

node* build(int preL, int preR, int inL, int inR)
{
	if (preL > preR)
		return NULL;
	int k;
	for (k = inL; k <= inR; k++)
	{
		if (pre[preL] == in[k])
			break;
	}
	node *root = new node(in[k]);
	int lenL = k - inL;
	root->left = build(preL+1, preL+lenL, inL, k-1);
	root->right = build(preL +lenL+ 1, preR, k+1, inR);
	return root;
}

void preOrder_iter(node* root)
{
	stack<node *> s;
	s.push(root);//起始于根节点
	while (!s.empty())
	{	
		node *temp = s.top(); s.pop(); //对每个右子树节点遍历左子树
		while (temp)//循环遍历左子树然后把右子树入栈
		{
			printf("%d ", temp->data);
			if (temp->right != NULL)
				s.push(temp->right);
			temp = temp->left;
		}
	}
}

void inOrder_iter(node* root)
{
	stack<node*> s;
	s.push(root);
	while (!s.empty())
	{
		while (root->left != NULL)
		{
			root = root->left;
			s.push(root);
		}
		root = s.top(); s.pop();
		printf("%d ", root->data);
		if (root->right != NULL)
			root = root->right;
	}

}

void postOrder(node* root)
{
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
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
	int n,id;
	cin >> n;

	for (int i = 0; i < 2 * n; i++)
	{
		cin >> p;
		if(p=="Push")
		{ 
			cin >> id;
			pre.push_back(id);
			input.push(id);
		}
		else
		{
			in.push_back(input.top());
			input.pop();
		}
	}

	node* root = build(0, n - 1, 0, n - 1);
	inOrder_iter(root);

	system("pause");
}