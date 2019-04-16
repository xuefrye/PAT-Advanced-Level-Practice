/*
1132 Cut Integer £¨20 ·Ö)
*/

#include<iostream>
#include<string>

using namespace std;
int n;
string z;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> z;
		int zint = stoi(z);
		string z1 = z.substr(0, z.size() / 2); int z1int = stoi(z1);
		string z2 = z.substr(z.size() / 2, z.size() / 2); int z2int = stoi(z2);
		if (z1int !=0 && zint % z1int ==0)
		{
			zint /= z1int;
			if (z2int != 0 && zint%z2int == 0 )
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
	}
}