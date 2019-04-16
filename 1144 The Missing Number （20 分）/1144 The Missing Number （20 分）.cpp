/*
1144 The Missing Number （20 分）
2019年2月22日03:34:22
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e6+10;
int h[maxn];

int main()
{
	int n,in;
	scanf("%d", &n);
	//vector<int> hs(n + 1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &in);
		if (in > 0)
		{
			h[in]++;
		}
	}
	bool flag = true;
	for (int i = 1; i <=n; i++)
	{
		if (h[i] == 0)
		{
			printf("%d", i);
			flag = false;
			break;
		}
	}

	if(flag)
		printf("%d", n+1);

	system("pause");
}