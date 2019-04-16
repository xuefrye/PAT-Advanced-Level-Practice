/*
1109 Group Photo £®25 ∑÷£©
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct person
{
	string name;
	int height;
};

bool cmp(person &a, person &b)
{
	if (a.height != b.height)
		return a.height > b.height;
	else
		return a.name < b.name;
}

vector<person> p;
const int maxn = 10010;
int n, k;
int row, front, rear;
string name; int height;

void formation(vector<person> &v)
{
	int pos = v.size() / 2;
	vector<person> u(v.size());
	for (int i = 0,j; i < v.size(); i++)
	{
		if (i % 2 == 0) j = i;
		else j = -i;

		u[pos+j] = v[i];
		pos += j;
	}
	
	bool first = true;
	for (int i = 0; i < u.size(); i++)
	{
		if (first)
		{
			printf("%s", u[i].name.c_str());
			first = false;
		}
		else
			printf(" %s", u[i].name.c_str());
	}
	printf("\n");
}

int main()
{
	cin >> n >> k; //n»À≈≈k––
	if (n%k == 0)
	{
		front = rear = n/k;
	}
	else
	{
		front = n / k;
		rear = n / k + n % k;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> name >> height;
		p.push_back(person{ name,height });
	}
	sort(p.begin(), p.end(), cmp);

	vector<person> in(p.begin(), p.begin() + rear);
	formation(in);

	for (int j=0; j < k-1;j++)
	{
		vector<person>in(p.begin()+rear+j* front, p.begin() + rear + (j+1) * front);
		formation(in);
	}
	system("pause");
}