/*
1079 Total Sales of Supply Chain £¨25 ·Ö£©
*/


#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
const int maxn = 100000;
struct node
{
	int layer = 1;
	int sell = -1;
	vector<int> child;
}nodes[maxn];

int n,k,childid;
double p, r;
double sum = 0;

void dfs(int id, int layer)
{
	if (nodes[id].child.size() == 0)
	{
		sum += nodes[id].sell * p * pow(1+r, layer-1) ;
		return;
	}
	else
	for (int i=0; i < nodes[id].child.size(); i++)
	{
		dfs(nodes[id].child[i], layer+1);
	}
}

int main()
{
	cin >> n >> p >> r;
	r /= 100;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		if (k != 0)
			for (int j = 0; j < k; j++)
			{
				cin >> childid;
				nodes[i].child.push_back(childid);
			}
		else
			cin >> nodes[i].sell;
	}

	dfs(0, 1);
	printf("%.1f", sum);

	system("pause");


}