/*1060 Are They Equal （25 分）
1.没有考虑前导0导致做题失败.
2.没有考虑小数点前都是零,小数点后也都是0的情况
3.没有考虑负幂的情况
4.erase 的删除 理解出错.如果填入1个整型是从这个整数下标开始一直删除到结尾.而不是只删除这一个.
*/
#define _CRT_SECURE_NO_WARNINGS
// 3 0.00123 0.000012345
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string num1, num2;
	int n, m, exp1 = 0, exp2 = 0; // 输入的指数,m是n的副本

	cin >> n >> num1 >> num2;
	//    int len1 = num1.size();
	//    int len2 = num2.size();
	//删除前导零
	while (num1.size() > 1 && num1[0] == '0')
		num1.erase(num1.begin());

	while (num2.size() > 1 && num2[0] == '0') //应该这么想当size = 1的时候不考虑删0,那么就是 size>1而不是大于0.
		num2.erase(num2.begin());

	if (num1[0] == '.') //说明是小数
	{
		num1.erase(num1.begin());
		while (num1[0] == '0') //删除小数前导0
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
			num1.erase(find1, 1); //erase 的删除 理解出错.如果填入1个整型是从这个整数下标开始一直删除到结尾.而不是只删除这一个.
		}
		m = n;
		while (m--)
			num1 += "0";
		num1 = num1.substr(0, n);
	}

	if (num2[0] == '.') //说明是小数
	{
		num2.erase(num2.begin());
		while (num2[0] == '0') //删除小数前导0
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