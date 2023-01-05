#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void	arr_dq(string& arr, deque<int>& dq)
{
	int	ele = 0;
	for (int i = 1; i + 1 < arr.size(); i++)
	{
		if (arr[i] == ',') {
			dq.push_back(ele);
			ele = 0;
		}
		else
			ele = 10 * ele + (arr[i] - '0');
	}
	if (ele)
		dq.push_back(ele);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	t;
	cin >> t;
	while (t--)
	{
		string	ac;
		int		n;
		string	arr;
		deque<int>	dq;
		int	err = 0;
		int	rev = 0;
		cin >> ac;
		cin >> n;
		cin >> arr;
		arr_dq(arr, dq);
		for (char c : ac)
		{
			if (c == 'D') {
				if (dq.empty()) {
					cout << "error" << '\n';
					err = 1;
					break ;
				}
				dq.pop_front();
			}
			else if (c == 'R')
				rev++;
		}
		if (err)
			continue ;
		if (rev % 2 == 1) 
			reverse(dq.begin(), dq.end());
		cout << "[";
		for (int i = 0; i < dq.size(); i++)
		{
			cout << dq[i];
			if (i + 1 != dq.size())
				cout << ',';
		}
		cout << "]" << '\n';
	}
	return (0);
}

