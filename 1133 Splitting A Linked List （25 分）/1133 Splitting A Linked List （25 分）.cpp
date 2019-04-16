/*
1133 Splitting A Linked List £¨25 ·Ö£©
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int head, n, k;
int addr, data1, next1;

struct node
{
	int addr;
	int data;
	int next;
	int order;
	node(){}
	node(int d,int n)
	{
		data = d; next = n; 
	}
}list[maxn];

bool cmp1(node& a, node &b)
{
	return a.data < b.data;
}

bool cmp2(node &a, node &b)
{
	return a.order < b.order;
}

vector<node> li;

int main()
{
	scanf("%d %d %d", &head, &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &addr, &data1, &next1);
		list[addr] = node(data1, next1);
	}

	int cnt = 1;
	for (int i = head; i != -1; i = list[i].next)
	{
		list[i].order = cnt++;
		list[i].addr = i;
		li.push_back(list[i]);
	}

	sort(li.begin(), li.end(), cmp1);

	int cnt1=0, cnt2=0, cnt3=0;//1Ð¡ÓÚÁã,2[0-k],3 >k
	for (int i = 0; i < li.size(); i++)
	{
		if (li[i].data < 0)
			cnt1++;
		else if (li[i].data >= 0 && li[i].data <= k)
			cnt2++;
		else
			cnt3++;
	}

	sort(li.begin(), li.begin() + cnt1, cmp2);
	sort(li.begin() + cnt1, li.begin() + cnt1 +cnt2, cmp2);
	sort(li.begin() + cnt1+cnt2, li.begin() + cnt1 + cnt2+cnt3, cmp2);

	for (int i = 0; i < li.size()-1; i++)
	{
		printf("%05d %d %05d\n", li[i].addr, li[i].data, li[i+1].addr);
	}
	printf("%05d %d -1\n", li[li.size()-1].addr, li[li.size()-1].data);
	system("pause");
}