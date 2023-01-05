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
	int	n, m;
	cin >> n >> m;
	deque<int> dq;
	for (int i = 0; i < n; i++)
		dq.push_back(i + 1);
	int	ret = 0;
	while (m--)
	{
		int	input;
		cin >> input;
		int	i = find(dq.begin(), dq.end(), input) - dq.begin();
		while (dq.front() != input)
		{
			if (i < dq.size() - i) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			ret++;
		}
		dq.pop_front();
	}
	cout << ret;
	return (0);
}

