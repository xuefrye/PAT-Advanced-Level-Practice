/*1060 Are They Equal ��25 �֣�
1.û�п���ǰ��0��������ʧ��.
2.û�п���С����ǰ������,С�����Ҳ����0�����
3.û�п��Ǹ��ݵ����
4.erase ��ɾ�� ������.�������1�������Ǵ���������±꿪ʼһֱɾ������β.������ֻɾ����һ��.
*/
#define _CRT_SECURE_NO_WARNINGS
// 3 0.00123 0.000012345
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string num1, num2;
	int n, m, exp1 = 0, exp2 = 0; // �����ָ��,m��n�ĸ���

	cin >> n >> num1 >> num2;
	//    int len1 = num1.size();
	//    int len2 = num2.size();
	//ɾ��ǰ����
	while (num1.size() > 1 && num1[0] == '0')
		num1.erase(num1.begin());

	while (num2.size() > 1 && num2[0] == '0') //Ӧ����ô�뵱size = 1��ʱ�򲻿���ɾ0,��ô���� size>1�����Ǵ���0.
		num2.erase(num2.begin());

	if (num1[0] == '.') //˵����С��
	{
		num1.erase(num1.begin());
		while (num1[0] == '0') //ɾ��С��ǰ��0
		{
			num1.erase(num1.begin());
			exp1--;
		}
		if (num1.size() == 0)
			exp1 = 0;
		m = n;
		while (m--)
			num1 += "0";
		num1 = num1.substr(0, n);
	}
	else
	{
		auto find1 = num1.find('.');
		if (find1 == string::npos)
		{
			if (num1 == "0")
				exp1 = 0;
			else
				exp1 = num1.size();
		}
		else
		{
			exp1 = find1;
			num1.erase(find1, 1); //erase ��ɾ�� ������.�������1�������Ǵ���������±꿪ʼһֱɾ������β.������ֻɾ����һ��.
		}
		m = n;
		while (m--)
			num1 += "0";
		num1 = num1.substr(0, n);
	}

	if (num2[0] == '.') //˵����С��
	{
		num2.erase(num2.begin());
		while (num2[0] == '0') //ɾ��С��ǰ��0
		{
			num2.erase(num2.begin());
			exp2--;
		}
		if (num2.size() == 0)
			exp2 = 0;
		m = n;
		while (m--)
			num2 += "0";
		num2 = num2.substr(0, n);
	}
	else
	{
		auto find2 = num2.find('.');
		if (find2 == string::npos)
		{
			if (num2 == "0")
				exp2 = 0;
			else
				exp2 = num2.size();
		}
		else
		{
			exp2 = find2;
			num2.erase(find2, 1);
		}
		m = n;

		while (m--)
			num2 += "0";
		num2 = num2.substr(0, n);
	}


	if (num1 == num2 && exp1 == exp2)
		cout << "YES 0." << num1 << "*10^" << exp1;
	else
		cout << "NO 0." << num1 << "*10^" << exp1 << " 0." << num2 << "*10^" << exp2;
	system("pause");
}