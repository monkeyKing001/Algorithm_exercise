#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<int> s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string cmd;
		int num;
		cin >> cmd;
		if (cmd.compare("add") == 0)
		{
			cin >> num;
			s.insert(num);
		}
		else if (cmd.compare("check") == 0)
		{
			cin >> num;
			if (s.find(num) == s.end())
				cout << "0\n";
			else
				cout << "1\n";
		}
		else if (cmd.compare("remove") == 0)
		{
			cin >> num;
			if (s.find(num) == s.end())
				continue ;
			else
				s.erase(num);
		}
		else if (cmd.compare("toggle") == 0)
		{
			cin >> num;
			if (s.find(num) == s.end())
				s.insert(num);
			else
				s.erase(num);
		}
		else if (cmd.compare("all") == 0)
		{
			for (int i = 0; i < 20; i++)
				s.insert(i + 1);
		}
		else if (cmd.compare("empty") == 0)
		{
			s.clear();
		}
	}
	return (0);
}

