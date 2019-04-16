/*
1129 Recommendation System £¨25 ·Ö£©
*/
#include<iostream>
#include<set>
struct node
{
	int id;
	int cnt;
	node(int i,int c):id(i),cnt(c){}

	bool operator<(const node &b)const
	{
		if (cnt != b.cnt)
			return cnt > b.cnt;
		else
			return id < b.id;
	}
};
using namespace std;
const int maxn = 50010;
int n, k, id;
int h[maxn];
set<node> ans;

int main()
{
	cin >> n >> k;
	cin >> id;
	h[id]++;
	ans.insert(node(id, h[id]));

	for (int i = 1; i < n; i++)
	{
		cin >> id;
		printf("%d:", id);

		int cntk = 0;
		for (auto it = ans.begin(); it != ans.end() && cntk < k; it++, cntk++)
		{
			printf(" %d", it->id);
		}
		printf("\n");

		auto it = ans.find(node(id, h[id]));
		if(it != ans.end())
			ans.erase(it);
		h[id]++;
		ans.insert(node(id, h[id]));
	}
	system("pause");
}