/*
1140 Look-and-say Sequence ��20 �֣�
2019��2��22��04:50:32
ע���
����48���ӡ���������ô˵��Ҳ����������
*/
#include<iostream>
#include<string>
using namespace std;

int main1()
{
	int d, n,cnt=1;
	string ans,temp;
	cin >> d >> n;
	if (n == 1)
	{
		printf("%d", d);
		return 0;
	}
	temp = to_string(d) + "1";
	
	for (int i = 2; i < n; i++)
	{
		for (int j=0;j<temp.size();j++)
		{
			if (j == temp.size() - 1 || temp[j] != temp[j + 1])
			{
				ans += temp[j] + to_string(cnt);
				cnt = 1;
			}
			else
			{
				cnt++;
			}
		}
		temp = ans;
		cnt = 1;
		ans.clear();
	}

	cout << temp;
	system("pause");
}

int main()
{
	int n;
	string d,ans;
	cin >> d >> n;
	ans = d;
	for (int k = 1; k < n; k++)
	{
		string temp ="";
		for (int i = 0, j; i < ans.size(); i = j)
		{
			for (j = i; j < ans.size() && ans[j] == ans[i]; j++);
			temp += ans[i] + to_string(j - i);
		}
		ans = temp;
	}
	cout << ans;
	system("pause");
}