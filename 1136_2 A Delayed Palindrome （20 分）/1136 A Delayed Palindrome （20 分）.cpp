/*
1136 A Delayed Palindrome £¨20 ·Ö£©
*/


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string rev(string s)
{
	reverse(s.begin(), s.end());
	return s;
}

string add(string a, string b)
{
	string ans="";
	int carry = 0;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		ans = to_string(((a[i] - '0') + (b[i] - '0') + carry) % 10) +ans;
		carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
	}
	if (carry == 1)
		ans = "1" + ans;
	return ans;
}

int main()
{
	string in, reversed,ans;
	cin >> in;

	for(int i=0;i<10;i++)
	{ 	
		if (in == rev(in))
		{
			printf("%s is a palindromic number.\n", in.c_str());
			system("pause"); return 0;
		}
		ans = add(in, rev(in));
		cout << in << " + " << rev(in) << " = " << ans << endl;
		in = ans;
	}
	printf("Not found in 10 iterations.\n");

	system("pause");
}