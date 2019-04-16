#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct node {
	int addr;
	int data;
	int next;
};

int fAddr,addr, n;
unordered_map<int,bool> exist;
vector<node> ans1, ans2;

int main()
{
	cin >> fAddr >> n;
	vector<node> nodes(100000);
	for (int i = 0; i < n; i++)
	{
		cin >> addr;
		nodes[addr].addr = addr;
		cin >> nodes[addr].data;
		cin >> nodes[addr].next;
	}

	while (fAddr != -1)
	{
		int id = abs(nodes[fAddr].data);
		if (exist[id] == false)
		{
			exist[id] = true;
			ans1.push_back(nodes[fAddr]);
		}
		else
		{
			ans2.push_back(nodes[fAddr]);
		}
		fAddr = nodes[fAddr].next;
	} 

	for (int i = 0; i < ans1.size(); i++)
	{
		if(i!=ans1.size()-1)
			printf("%05d %d %05d\n", ans1[i].addr, ans1[i].data, ans1[i + 1].addr);
		else
			printf("%05d %d -1\n", ans1[i].addr, ans1[i].data);
	}

	for (int i = 0; i < ans2.size(); i++)
	{
		if (i != ans2.size() - 1)
			printf("%05d %d %05d\n", ans2[i].addr, ans2[i].data, ans2[i + 1].addr);
		else
			printf("%05d %d -1\n", ans2[i].addr, ans2[i].data);
	}
	system("pause");
}