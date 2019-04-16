//1060 Are They Equal （25 分）
//没有考虑前导0导致做题失败.
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>

using namespace std;

int main1()
{
	string num1, num2;
	int n,exp;
	cin >> n >> num1 >> num2;

	auto find1 = num1.find("."); //保存小数点位置.
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

	if (find1 != find2) //小数点位置不一样必定不相等.
		is_equal = false;
	else if (find1 < n) //如果有效数字包括小数点
	{
		for (int i = 0;i < n+1;i++)
			if (num1[i] != num2[i])
			{
				is_equal = false;
				break;
			}
	}
	else//不包括小数点
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