/*
1127 ZigZagging on a Tree £¨30 ·Ö£©
*/

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct node {
	int data;
	int layer;
	int layerOrder;
	node* left;
	node* right;
	node(int d, node*l=NULL, node* r=NULL,int la =0,int lao=0)
	{
		data = d; left = l; right = r; layer = la; layerOrder = lao;
	} 
};
const int maxn = 40;
int n;
int in[maxn], post[maxn];
int visited[maxn] = { false };
vector<node> ans;

node* build(int postL, int postR, int inL, int inR)
{
	if (inL > inR) return NULL;

	node* root = new node(post[postR]);

	int pos = 0;
	for (int i = inL; i <= inR; i++)
		if (post[postR] == in[i])
		{
			pos = i; break;
		}

	int lenL = pos - inL;

	root->left = build(postL,postL+lenL-1,inL,pos-1);
	root->right = build(postL+lenL,postR-1,pos+1,inR);
	return root;
}

bool cmp(node &a, node&b)
{
	if (a.layer != b.layer)
		return a.layer < b.layer;
	else
		if (a.layer % 2 == 1)
			return a.layerOrder > b.layerOrder;
		else
			return a.layerOrder < b.layerOrder;
}

void level(node* root)
{
	queue<node> qnode;
	qnode.push(node(root->data, root->left, root->right, 1, 1));

	while (!qnode.empty())
	{
		node temp = qnode.front(); qnode.pop();
		ans.push_back(temp);
		int layerO = 1;
		if(temp.left != NULL)
			qnode.push(node(temp.left->data, temp.left->left, temp.left->right, temp.layer + 1));
		if (temp.right != NULL)
			qnode.push(node(temp.right->data, temp.right->left, temp.right->right, temp.layer + 1));
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> in[i];
	for (int i = 0; i < n; i++)
		cin >> post[i];

	node* root = build(0, n - 1, 0, n - 1);
	level(root);
	for (int i = 0; i < ans.size(); i++)
		ans[i].layerOrder = i + 1;

	sort(ans.begin(), ans.end(), cmp);

	printf("%d", ans[0].data);
	for (int i = 1; i < ans.size(); i++)
		printf(" %d", ans[i].data);
	system("pasue");
}