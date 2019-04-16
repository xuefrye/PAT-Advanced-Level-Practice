#include<iostream>
#include<string>
using namespace std;

int longestPalindrome(string s) {
	if (s == "") return 0;

	int size = s.size();
	bool dp[1000][1000] = { 0 };
	int ans = 0, ansi = 0, ansj = 0;

	for (int i = 0; i < s.size(); i++)
	{
		dp[i][i] = 1;
		ansi = i;
		ansj = i;
	}

	for (int i = 0; i < s.size() - 1; i++)
		if (s[i] == s[i + 1])
		{
			dp[i][i + 1] = 1;
			ansi = i;
			ansj = i + 1;
		}

	for (int len = 3; len <= s.size(); len++)
	{
		for (int i = 0; i < s.size() - len + 1; i++)
		{
			int j = i + len - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
			{
				dp[i][j] = 1;
				ansi = i;
				ansj = j;
			}

		}
	}
	return ansj - ansi + 1;
}


int main()
{
	string s;
	getline(cin, s);
	printf("%d", longestPalindrome(s));
}