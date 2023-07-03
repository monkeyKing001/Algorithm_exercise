#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m, x;
int g[1001][1001];
int cost[1001][1001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> x;
	vector<vector <pair<int, int>>> adj_list;
	for (int i = 0; i < n + 1; i++)
	{
		vector <pair<int, int>> v;
		adj_list.push_back(v);
	}
	for (int i = 0; i < m; i++)
	{
		int from_v;
		int to_v;
		int cost_to;
		cin >> from_v >> to_v >> cost_to;
		adj_list[from_v].push_back({to_v, cost_to});
		g[from_v][to_v] = cost_to;
		cost[from_v][to_v] = cost_to;
	}
	return (0);
}

