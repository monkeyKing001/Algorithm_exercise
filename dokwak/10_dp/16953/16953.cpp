#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
long long n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	queue <pair <long long, int>> q;
	q.push({n, 1});

	while (q.size() != 0)
	{
		long long num = q.front().first;
		int step = q.front().second;
		q.pop();
		if (num == m)
		{
			cout << step;
			return (0);
		}
		for (int i = 0; i < 2; i++)
		{
			long long next_num;
			int next_step = step + 1;
			if (i == 0)
				next_num = num * 2;
			else
				next_num = num * 10 + 1;
			if (next_num <= m)
				q.push({next_num, next_step});
		}
	}
	cout << "-1";
	return (0);
}

