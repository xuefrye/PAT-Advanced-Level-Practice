/*
1124 Raffle for Weibo Followers ��20 �֣�
12���ӣ����Ѷ�
*/
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

map<string, int> winner;


int main()
{
	string name; int m, n, s;
	int wcnt = 0;
	vector<string> list; list.push_back("0");//��1��ʼ
	cin >> m >> n >> s;
	for (int i = 0; i < m; i++)
	{
		cin >> name;
		list.push_back(name);
	}

	for (int i = s; i < list.size();i+=n)
	{
		while (true) //ע�������˼��ֻҪû�оͼ�����ֻҪ�о�break��
		{
			if (winner[list[i]] == false)
			{
				winner[list[i]] = true;
				cout << list[i] << endl;
				wcnt++;
				break;
			}
			else
			{
				i++;
			}
			if (i >= list.size()) //��ֹ����ѭ��
				break;
		}
	}

	if (wcnt == 0)
		printf("Keep going...\n");

}