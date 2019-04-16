#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using ll = long long;

int main()
{
	int aa;
	char str[] = "1.1.1";
	sscanf(str, "%f", &aa);
	vector<int> num;
	auto result = find(num.begin(), num.end(), 3);
	int a, b=0, c=0;
	a = 1;
	a < 0 ? b: c = 5;
	cout << b << " " << c;
	system("pause");

}