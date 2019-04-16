/*
1102 Invert a Binary Tree （25 分）
29分钟搞定.
注意点.
1.又出现了一个小问题,由于复制粘贴.没改过来.
*/
#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

const int maxn = 100;
int n;
int flag[maxn] = { false };
int first = true;
struct node
{
	int data;
	int left;
	int right;
	node(){}
	node(int d,int l=-1, int r=-1):data(d),left(l),right(r){}
}tree[maxn];


void level(int root)
{
	queue<int> qnode;
	qnode.push(tree[root].data);
	while (!qnode.empty())
	{
		int temp = qnode.front(); qnode.pop();
		if(first)
		{ 
			printf("%d", tree[temp].data);
			first = false;
		}
		else
			printf(" %d", tree[temp].data);

		if(tree[temp].right !=-1)
			qnode.push(tree[temp].right);
		if (tree[temp].left != -1)
			qnode.push(tree[temp].left);
	}

	first = true;
}

void inorder(int root)
{
	if (root == -1)
		return;

	inorder(tree[root].right);

	if (first)
	{
		printf("%d", tree[root].data);
		first = false;
	}
	else
		printf(" %d", tree[root].data);

	inorder(tree[root].left);
}

int main()
{
	string in1, in2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> in1 >> in2;
		tree[i].data = i;
		if (in1 == "-")
			tree[i].left = -1;
		else
		{ 
			tree[i].left = stoi(in1);
			flag[stoi(in1)] = true;
		}

		if (in2 == "-")
			tree[i].right = -1;
		else
		{
			tree[i].right = stoi(in2);
			flag[stoi(in2)] = true;
		}
	}

	int root;
	for (root = 0; root < n; root++)
	{
		if (flag[root] == false)
			break;
	}

	level(root);
	cout << endl;
	inorder(root);
	system("pause");
}