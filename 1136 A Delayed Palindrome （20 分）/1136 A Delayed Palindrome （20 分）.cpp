/*
1136 A Delayed Palindrome £¨20 ·Ö£©
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


struct bigint
{
	int n[1001] = { 0 };
	int len=0;
	bigint operator+(bigint &b)
	{
		bigint c;
		int carry = 0;
		int i;
		for (i = 0; i < max(len,b.len); i++)
		{
			c.n[i] = (n[i] + b.n[i]+carry) % 10;
			carry = (n[i] + b.n[i] + carry) / 10;
		}

		if (carry == 1)
		{
			c.len = max(len, b.len) + 1;
			c.n[i] = 1;
		}
		else
		{
			c.len = max(len, b.len);
		}
		return c;
	}
};

ostream& operator<<(ostream& in, bigint &a)
{
	for (int i = a.len - 1; i >= 0; i--)
	{
		printf("%d", a.n[i]);
	}
	return in;
}


bigint reverse(bigint &a)
{
	bigint b;
	b.len = a.len;
	for (int i = a.len - 1,j=0; i >= 0; i--,j++)
	{
		b.n[j] = a.n[i];
	}
	return b;
}

bool huiwen(bigint &a)
{
	for (int i = 0; i < a.len/2; i++)
	{
		if (a.n[i] != a.n[a.len - i-1])
			return false;
	}
	return true;
}

int main()
{
	bigint a, b,c;
	string in;
	cin >> in;
	for (int i = in.size() - 1,j=0; i >= 0; i--,j++)
	{
		a.n[j] = in[i]-'0'; a.len++;
	}
	b = reverse(a);
	c = a + b;
	for (int i = 0; i < 10; i++)
	{
		cout << a << " + " << b << " = " << c << endl;
		if (huiwen(c))
		{
			cout << c << " is a palindromic number.\n";
			system("pause");
			return 0;
		}
		a = c;
		b = reverse(a);
		c = a + b;

	}
	cout << "Not found in 10 iterations.\n";
	system("pause");
}