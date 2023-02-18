#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int tree[100];
int p[100];
vector <int> adj_list[100];
int n;
int no = '.' - 'A';
void pre(int pos)
{
	if (pos == no)
		return ;
	cout << (char)(pos + 'A');
	for (int i = 0; i < adj_list[pos].size(); ++i)
		pre(adj_list[pos][i]);	
}
void post(int pos)
{
	if (pos == no)
		return ;
	for (int i = 0; i < adj_list[pos].size(); ++i)
		post(adj_list[pos][i]);	
	cout << (char)(pos + 'A');
}
void inord(int pos)
{
	if (pos == no)
		return ;
	for (int i = 0; i < adj_list[pos].size(); ++i)
	{
		if (i == 1)
			cout << (char)(pos + 'A');
		inord(adj_list[pos][i]);	
	}
}
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char char1, char2, char3;
		cin >> char1 >> char2 >> char3;
		int pos1, pos2, pos3;
		pos1 = char1 - 'A';
		pos2 = char2 - 'A';
		pos3 = char3 - 'A';
		adj_list[pos1].push_back(pos2);
		adj_list[pos1].push_back(pos3);
	}
	pre(0);
	cout << "\n";
	inord(0);
	cout << "\n";
	post(0);
	cout << "\n";
	return (0);
}
