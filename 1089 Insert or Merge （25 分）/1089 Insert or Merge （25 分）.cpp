/*
1089 Insert or Merge £¨25 ·Ö£©
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 110;
int n;

int main()
{
	cin >> n;
	vector<int> seq1(n), seq2(n);
	for (int i = 0; i < n; i++)
		cin >> seq1[i];

	for (int i = 0; i < n; i++)
		cin >> seq2[i];

	int rev = -1;
	for (int i = 1; i < n; i++)
	{
		if (seq2[i] < seq2[i - 1])
		{
			rev = i;
			break;
		}
	}

	bool insert = true;
	for (int i = rev; i < n; i++)
	{
		if (seq1[i] != seq2[i])
		{
			insert = false; break;
		}
	}

	if (insert)
	{
		printf("Insertion Sort\n");
		sort(seq2.begin(), seq2.begin() + rev + 1);
		printf("%d", seq2[0]);
		for (int i = 1; i < n; i++)
			printf(" %d", seq2[i]);
	}
	else
	{
		printf("Merge Sort\n");
		int k = 1; bool flag = true;
		while (flag)
		{
			if (seq1 == seq2)
				flag = false;
			k = k * 2;
			for (int i = 0; i < n / k; i++)
				sort(seq1.begin() + i * k, seq1.begin() + (i + 1)*k);
			sort(seq1.begin() +( n / k) * k, seq1.begin() + n);
		}
		printf("%d", seq1[0]);
		for (int i = 1; i < n; i++)
			printf(" %d", seq1[i]);
	}

}