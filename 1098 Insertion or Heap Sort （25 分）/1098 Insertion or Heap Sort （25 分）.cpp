/*
1098 Insertion or Heap Sort £¨25 ·Ö£©
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
const int maxn = 110;


void downAdjust(int low, int high, vector<int> &heap)
{
	int father = low;
	int son = 2 * low;
	while (son <= high)
	{
		if (son + 1 <= high && heap[son] < heap[son + 1])
		{
			son++;
		}
		if (heap[father] >= heap[son])
			break;
		
		swap(heap[father], heap[son]);
		father = son;
		son = father * 2;
	}
}
int main()
{	
	int k = 2;	
	bool is_insert = true;
	cin >> n;
	vector<int> input(n+2), sorted(n+2);
	for (int i = 1; i <= n; i++) cin >> input[i];
	for (int i = 1; i <= n; i++) cin >> sorted[i];

	while (k <= n && sorted[k - 1] <= sorted[k]) k++;
	int Index = k;
	while (k <= n && input[k] == sorted[k]) k++;
	if(k!=n+1)
		is_insert=false;

	//for (k = 2; k <= n; k++)
	//	if (sorted[k - 1] >= sorted[k])
	//		break;
	//for (int i = k; i <= n; i++)
	//	if (input[i] != sorted[i])
	//	{
	//		is_insert = false;
	//		break;
	//	}

	if (is_insert)
	{
		printf("Insertion Sort\n");
		sort(sorted.begin()+1, sorted.begin() + Index +1);
		//sort(sorted.begin()+1, sorted.begin() + k +1);
		printf("%d", sorted[1]);
		for(int i=2;i<=n;i++)
			printf(" %d", sorted[i]);
	}
	else
	{
		printf("Heap Sort\n");
		int p = n;
		//while (p > 2 && sorted[p] >= sorted[1]) p--;
		for (p = n; p >1; p--)
			if (sorted[1] > sorted[p])
				break;

		swap(sorted[1], sorted[p]);
		downAdjust(1, p - 1, sorted);
		printf("%d", sorted[1]);
		for (int i = 2; i <= n; i++)
			printf(" %d", sorted[i]);
	}
	system("pause");
}

