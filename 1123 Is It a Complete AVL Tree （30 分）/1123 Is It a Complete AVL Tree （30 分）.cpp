/*

1123 Is It a Complete AVL Tree £¨30 ·Ö£©
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	int height;
	node(int d,int h=1,node* l=NULL,node* r=NULL):data(d),height(h),left(l),right(r){}
};

int getHeight(node* root)
{
	if (root == NULL)
		return 0;
	else
		return root->height;
}

int getBalance(node* root)
{
	return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(node* root)
{
	root->height = max(getHeight(root->left), getHeight(root->right))+1;
}

void Rrotation(node* &root)
{
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateHeight(root); updateHeight(temp);
	root = temp;
}

void Lrotation(node* &root)
{
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateHeight(root); updateHeight(temp);
	root = temp;
}

void insert(node* &root, int data)
{
	if (root == NULL)
	{
		root = new node(data);
		return;
	}
	if (data < root->data)
	{
		insert(root->left, data);
		updateHeight(root);
		if (getBalance(root) == 2)
		{
			if (getBalance(root->left) == 1) //LL
				Rrotation(root);
			else if (getBalance(root->left) == -1)
			{
				Lrotation(root->left);
				Rrotation(root);
			}
		}
	}
	else
	{
		insert(root->right, data);
		updateHeight(root);
		if (getBalance(root) == -2)
		{
			if (getBalance(root->right) == -1) //RR
				Lrotation(root);
			else if (getBalance(root->right) == 1)//RL
			{
				Rrotation(root->right);
				Lrotation(root);
			}
		}
	}
}

int ctree[10000];
void buildCtree(node* root, int idx)
{
	ctree[idx] = root->data;
	if (root->left != NULL)
		buildCtree(root->left, idx * 2);
	if(root->right !=NULL)
		buildCtree(root->right, idx * 2 + 1);
}

int main()
{
	int n; node* root = NULL;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int in; cin >> in;
		insert(root, in);
	}

	fill(ctree, ctree + 10000, -1);
	buildCtree(root, 1);
	bool isCtree = true;
	for (int i = 1; i <= n; i++)
	{
		if (ctree[i] == -1)
		{
			isCtree = false; break;
		}
	}

	bool first = true;
	for (int i = 1; i < 10000; i++)
	{
		if (first)
		{
			first = false;
			if (ctree[i] != -1)
				printf("%d", ctree[i]);
		}
		else
			if (ctree[i] != -1)
				printf(" %d", ctree[i]);
	}

	if (isCtree)
		printf("\nYES\n");
	else
		printf("\nNO\n");
	system("pause");
}
