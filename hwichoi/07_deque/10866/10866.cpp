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
	int	n;
	cin >> n;
	deque<int>	dq;
	while (n--)
	{
		string	input;
		cin >> input;
		if (input == "push_front")
		{
			int	i;
			cin >> i;
			dq.push_front(i);
		}
		else if (input == "push_back")
		{
			int	i;
			cin >> i;
			dq.push_back(i);
		}
		else if (input == "pop_front")
		{
			if (dq.empty())
				cout << "-1" << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (input == "pop_back")
		{
			if (dq.empty())
				cout << "-1" << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (input == "size")
			cout << dq.size() << '\n';
		else if (input == "empty")
			cout << (dq.empty() == 1) << '\n';
		else if (input == "front")
		{
			if (dq.empty())
				cout << "-1" << '\n';
			else
				cout << dq.front() << '\n';
		}
		else if (input == "back")
		{
			if (dq.empty())
				cout << "-1" << '\n';
			else
				cout << dq.back() << '\n';
		}
	}
	return (0);
}
