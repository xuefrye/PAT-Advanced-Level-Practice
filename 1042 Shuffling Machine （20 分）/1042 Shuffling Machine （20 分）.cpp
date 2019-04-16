/*
1042 Shuffling Machine （20 分）
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> deck;
const int maxn = 55;
int order[maxn];
vector<string> shuffed(55);
int main()
{
	deck.push_back("0"); //从1开始,先把0号位填上
	for (int i = 1; i <= 13; i++) deck.push_back(string("S") + to_string(i));
	for (int i = 1; i <= 13; i++) deck.push_back(string("H") + to_string(i));
	for (int i = 1; i <= 13; i++) deck.push_back(string("C") + to_string(i));
	for (int i = 1; i <= 13; i++) deck.push_back(string("D") + to_string(i));
	deck.push_back("J1"); deck.push_back("J2");

	int n;
	cin >> n;
	for (int i = 1; i <= 54; i++)
	{
		cin >> order[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= 54; j++)
		{
			shuffed[order[j]] = deck[j];
		}
		deck = shuffed;
	}

	cout << deck[1];
	for (int i = 2; i <= 54; i++)
	{
		cout << " " << deck[i];
	}
	system("pause");
}