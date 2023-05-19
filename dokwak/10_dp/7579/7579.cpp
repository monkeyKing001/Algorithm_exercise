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
int sol = INT_MAX;
int dp[101][10001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n; //app num
	cin >> m; //need memory
	vector <pair<int, int>> app;
	int total_cost = 0;
	for (int i = 0; i < n; i++)
	{
		int mem;
		cin >> mem;
		app.push_back({mem, 0});
	}
	for (int i = 0; i < n; i++)
	{
		int cost;
		cin >> cost;
		app[i].second = cost;
		total_cost += cost;
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= total_cost; j++)
		{
			int app_mem = app[i].first;
			int app_cost = app[i].second;
			if (j >= app_cost)
			{
				if (app_mem + dp[i - 1][j - app_cost] > dp[i - 1][j])
					dp[i][j] = app_mem + dp[i - 1][j - app_cost];
				else
					dp[i][j] = dp[i- 1][j];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
			if (dp[i][j] >= m && j < sol)
				sol = j;
		}
	}
	cout << sol;
}
