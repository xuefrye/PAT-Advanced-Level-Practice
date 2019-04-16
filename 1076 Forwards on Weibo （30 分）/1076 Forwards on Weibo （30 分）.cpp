/*
1076 Forwards on Weibo （30 分）
2019年2月12日22:28:39
这是第一个在时间限制之内做出来的30分题目!
注意点:
1.搞反了关注与粉丝的邻接矩阵
user_list是关注列表.
题意是自顶向下,从被关注者向下追寻.
要通过被关注者找到粉丝G[user_list][i] user->i号
2.l的取值范围,第一层节点是1层,而我写的是0层,所以最后判断需要用<l而不是<=l
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
struct user
{
	int id;
	int layer;
	user(){}
	user(int i, int l = 1) :id(i), layer(l){}
};

const int maxn = 1010;
int G[maxn][maxn] = { 0 };
bool inqueue[maxn] = { false };
int n, l, k, kneed;
int mi, user_list;

int bfs(int userid)
{
	int cnt = 0;
	queue<user> quser;
	quser.push(user(userid));
	inqueue[userid] = true;
	while (!quser.empty())
	{
		user temp = quser.front();
		quser.pop();

		for (int i = 1; i <= n; i++)
		{
			if (G[temp.id][i] != 0 && inqueue[i] == false && temp.layer <= l)
			{
				quser.push(user(i, temp.layer + 1));
				inqueue[i] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main()
{
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
	{
		cin >> mi;
		for (int j = 0; j < mi; j++)
		{
			cin >> user_list;
			G[user_list][i] = 1; //能否通过追随者user_list找到i,也就是说用户i有没有用户userlist这个粉丝.
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> kneed;
		cout << bfs(kneed) << endl;
		fill(inqueue, inqueue + maxn, false); //重置inqueue表
	}
	system("pause");
}