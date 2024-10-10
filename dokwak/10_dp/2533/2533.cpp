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
int max_num = 1111000;
vector<vector<int>> dp;
vector<vector<int>>g;
int dfs(int cur_node, int choice, int parent){
	if (dp[cur_node][choice] != -1)
		return (dp[cur_node][choice]);
	int init_num = choice; 
	dp[cur_node][choice] = init_num;
	//if node is not early adaptor, all of his friends must be e.a
	for (int i = 0; i < g[cur_node].size(); i++) {
		int next = g[cur_node][i];
		if (next == parent)
			continue;
		if (choice == 0)
			dp[cur_node][choice] += dfs(next, 1, cur_node);
		else if (choice == 1)
			dp[cur_node][choice] += min(dfs(next, 0, cur_node), dfs(next, 1, cur_node));
	}
	return (dp[cur_node][choice]);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n + 1);
	dp.resize(n + 1, vector<int>(2, -1));
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	sol = min(dfs(1, 0, 0), dfs(1, 1, 0));
	cout << sol << "\n";
	return (0);
}

