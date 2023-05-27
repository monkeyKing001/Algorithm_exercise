#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int dp[1000001];
	int dp2[1000001];
//	queue <int> pq;
	priority_queue <int> pq;
	fill_n(dp, 1000001, 1000001);
	fill_n(dp2, 1000001, 1000001);
	dp[1] = 0;
	dp2[1] = 1;
	pq.push(1);
	while (pq.size())
	{
//		int cur = pq.front();
		int cur = pq.top();
		int cur_step = dp[cur];
		pq.pop();
		for (int i = 0; i < 3; i++)
		{
			int next = cur * 3;
			if (i == 1)
				next = cur * 2;
			else if (i == 2)
				next = cur + 1;
			if (next <= n && dp[next] > dp[cur] + 1)
			{
				dp[next] = dp[cur] + 1;
//				cout << "dp[" << next << "]: " << dp[next] << "\n";
				dp2[next] = cur;
				pq.push(next);
			}
		}
	}

	//how many step do we need?
	cout << dp[n] << "\n";

	//what is the path?
	cout << n << " ";
	while (n != 1)
	{
		cout << dp2[n] << " ";
		n = dp2[n];
	}
	return (0);
}

