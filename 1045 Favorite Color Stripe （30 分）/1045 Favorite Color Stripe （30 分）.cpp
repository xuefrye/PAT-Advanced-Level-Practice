#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int maxn = 1e4 + 10;
vector<int> seqTable,favTable;
int n, m, l, x;
bool h[maxn];
int dp[maxn];
unordered_map<int, int>color2order; //, order2color;


int cnt = 1;
int toOrder(int i)
{
	if (color2order[i] == 0)
	{
		color2order[i] = cnt;
		//order2color[cnt] = i;
		return cnt++;
	}
	else
		return color2order[i];
}


int rec()
{
	int maxlen = 0;
	for (int i = 0; i < seqTable.size(); i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (seqTable[i] >= seqTable[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		maxlen = max(maxlen, dp[i]);
	}

	return maxlen;
}

int main()
{
	freopen("1045.txt", "r", stdin);
	cin >> n; 

	cin >> m; 
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		favTable.push_back(toOrder(x));
		h[x] = true;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> x;
		if (h[x] == true)
			seqTable.push_back(toOrder(x));
	}

	printf("%d", rec());
}