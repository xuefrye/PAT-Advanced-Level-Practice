/*
1084 Broken Keyboard £¨20 ·Ö£©
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
string a, b;
map<char, bool> visited;
int main()
{
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
			a[i] = a[i] + 'A'-'a';
	}
	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] >= 'a' && b[i] <= 'z')
			b[i] = b[i] + 'A' - 'a';
	}

	for (int i = 0; i < a.size(); i++)
	{
		if (visited[a[i]] == false)
		{
			visited[a[i]] = true; bool exist = false;
			for (int j = 0; j < b.size(); j++)
			{
				if (a[i] == b[j])
				{
					exist = true; break;
				}
			}
			if (!exist)
				printf("%c", a[i]);

		}
	}
	system("pause");
}