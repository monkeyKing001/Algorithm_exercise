#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	map<string, int> not_hear;
	vector<string> not_hear_v;
	map<string, int> not_seen;
	vector<string> not_seen_v;
	map<string, int> not_seen_hear_v;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		not_hear.insert(make_pair(name, i));
		not_hear_v.push_back(name);
	}
	for (int i = 0; i < m; i++)
	{
		string name;
		cin >> name;
		not_seen.insert(make_pair(name, i));
		not_seen_v.push_back(name);
	}
	for (int i = 0; i < not_hear_v.size(); i++)
	{
		string t_name = not_hear_v[i];
		if (not_seen.find(t_name) != not_seen.end())
			not_seen_hear_v.insert(make_pair(t_name, i));
	}
	cout << not_seen_hear_v.size() << "\n";
	map<string, int>::iterator it = not_seen_hear_v.begin();
	for (; it != not_seen_hear_v.end(); it++)
		cout << it -> first << "\n";
	return (0);
}

