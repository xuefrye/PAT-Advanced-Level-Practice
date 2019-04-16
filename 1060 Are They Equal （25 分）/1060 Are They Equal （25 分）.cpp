//1060 Are They Equal ��25 �֣�
//û�п���ǰ��0��������ʧ��.
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;

int main1()
{
	string num1, num2;
	int n,exp;
	cin >> n >> num1 >> num2;

	auto find1 = num1.find("."); //����С����λ��.
	auto find2 = num2.find(".");

	if (find1 == string::npos)
	{
		num1 += ".";
		find1 = num1.length()-1;
	}
	if (find2 == string::npos)
	{
		num2 += ".";
		find2 = num2.length()-1;
	}

	bool is_equal = true;

	if (find1 != find2) //С����λ�ò�һ���ض������.
		is_equal = false;
	else if (find1 < n) //�����Ч���ְ���С����
	{
		for (int i = 0;i < n+1;i++)
			if (num1[i] != num2[i])
			{
				is_equal = false;
				break;
			}
	}
	else//������С����
	{
		for (int i = 0;i < n;i++)
			if (num1[i] != num2[i])
			{
				is_equal = false;
				break;
			}
	}

	string substr1 = num1.substr(0, n);
	string substr2 = num2.substr(0, n);
	bool is_zero1 = true;
	bool is_zero2 = true;

	for (auto each : substr1)
	{
		if (each != '0')
		{
			is_zero1 = false;
			break;
		}
	}

	for (auto each : substr2)
	{
		if (each != '0')
		{
			is_zero2 = false;
			break;
		}
	}


	if (is_equal)
	{
		cout << "YES ";
		if (is_zero1)
			cout << "0";
		else
			cout << "0." << substr1 << "*10^" << find1;
	}
	else
	{
		cout << "NO ";
		if (is_zero1)
			cout << "0";
		else
			cout << "0." << substr1 << "*10^" << find1;
		if (is_zero2)
			cout << " 0";
		else
			cout << " 0." << substr2 << "*10^" << find2;
	}

	system("pause");
	return 0;
}