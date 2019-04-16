/*
1138 Postorder Traversal £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int in[50010], pre[50010], post[50010];
int n;

int flag1 = true;
void postOrder1(int preL, int preR, int inL, int inR)
{
	if (preL > preR )
		return;

	int i;
	for (i = inL; i <= inR; i++)
	{
		if (pre[preL] == in[i])
		{
			break;
		}
	}
	int lenL = i - inL;
	postOrder1(preL + 1, preL + lenL, inL, i - 1);
	postOrder1(preL + lenL+1, preR, i + 1, inR);
	if (true)
	{
		printf("%d ", pre[preL]); //
		flag1 = false;
	}
}

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}

	//node *root = build(0, n - 1, 0, n - 1);
	postOrder1(0,n-1,0,n-1);

	system("pause");
}