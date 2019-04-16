/*
1076 Forwards on Weibo ��30 �֣�
2019��2��12��22:28:39
���ǵ�һ����ʱ������֮����������30����Ŀ!
ע���:
1.�㷴�˹�ע���˿���ڽӾ���
user_list�ǹ�ע�б�.
�������Զ�����,�ӱ���ע������׷Ѱ.
Ҫͨ������ע���ҵ���˿G[user_list][i] user->i��
2.l��ȡֵ��Χ,��һ��ڵ���1��,����д����0��,��������ж���Ҫ��<l������<=l
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
			G[user_list][i] = 1; //�ܷ�ͨ��׷����user_list�ҵ�i,Ҳ����˵�û�i��û���û�userlist�����˿.
		}
	}

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> kneed;
		cout << bfs(kneed) << endl;
		fill(inqueue, inqueue + maxn, false); //����inqueue��
	}
	system("pause");
}