#include<cstdio>
#include<string>
using namespace std;

int main()
{
	int n;
	scanf("%d", n);
	string str;
	for (int i = 1; i <= n; i++)
	{
		sprintf(str.c_str, "%s", i);
	}

	printf("%s", str);
	system("pause");
}