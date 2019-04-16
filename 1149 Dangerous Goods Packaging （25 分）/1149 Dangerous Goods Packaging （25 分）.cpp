/*
1149 Dangerous Goods Packaging £¨25 ·Ö£©
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

set<int> paired[100000];
int n, m, k;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int id1, id2;
		cin >> id1 >> id2;
		paired[id1].insert(id2);
		paired[id2].insert(id1);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> k;
		int id; vector<int> goods;
		goods.clear();
		for (int j = 0; j < k; j++)
		{
			cin >> id;
			goods.push_back(id);
		}

		bool flag = true;
		for (int j = 0; j < goods.size()-1; j++)
		{
			for (int x = j + 1; x < goods.size(); x++)
			{
				if (paired[goods[j]].find(goods[x]) != paired[goods[j]].end())
				{
					flag = false;
					break;
				}
			}
			if (flag == false)
				break;
		}

		if (flag) 
			cout << "Yes\n";
		else 
			cout << "No\n";
	}
	system("pause");
}