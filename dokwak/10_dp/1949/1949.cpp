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
int sol = 0;

vector<int> info;
vector<vector<int>> g;
vector<vector<int>> dp;

int dfs(int node, int choice, int parent){
	if (dp[node][choice] != -1)
		return dp[node][choice];
	int start_num = choice == 1 ? info[node] : 0;
	dp[node][choice] = start_num;
	for (int i = 0; i < g[node].size(); i++) {
		int next = g[node][i];
		if (next == parent)
			continue;
		if (choice == 0)
			dp[node][choice] += max(dfs(next, 0, node), dfs(next, 1, node));
		else
			dp[node][choice] += dfs(next, 0, node);
	}
	return (dp[node][choice]);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	info.resize(n + 1, 0);
	g.resize(n + 1);
	dp.resize(n + 1, vector<int> (2, -1));
	for (int i = 0; i < n; i++)
		cin >> info[i + 1];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	sol = max(dfs(1, 0, 0), dfs(1, 1, 0));
	cout << sol << "\n";
	return (0);
}

