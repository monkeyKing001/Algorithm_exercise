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
int max_cost = 100001;
#define COST first
#define NODE second
using edge_info = pair<int, int>;//to, cost
using travel_info = pair<int, int>; //cost, from to

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> x;
	vector<vector<edge_info>> g(n + 1);
	vector<int> dp(n + 1, max_cost);
	vector<bool> visited(n + 1, false);
	vector<vector<edge_info>> reverse_g(n + 1);
	vector<int> reverse_dp(n + 1, max_cost);
	vector<bool> reverse_visited(n + 1, false);
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		g[u].push_back({cost, v});
		reverse_g[v].push_back({cost, u});
	}
	priority_queue<travel_info, vector<travel_info>, greater<travel_info>> pq;
	visited[0] = true;
	dp[x] = 0;
	//-1 시작은 안되나?
	pq.push({0, x});
	while (pq.size() != 0){
		auto [cur_cost, node] = pq.top();
		pq.pop();
		if (visited[node])
			continue;
		visited[node] = true;
		for (int i = 0; i < g[node].size(); i++) {
			auto [next_cost, next_node] = g[node][i];
			if (!visited[next_node] && dp[next_node] > cur_cost + next_cost){
				dp[next_node] = cur_cost + next_cost;
				pq.push({dp[next_node], next_node});
			}
		}
	}
	reverse_visited[0] = true;
	reverse_dp[x] = 0;
	pq.push({0, x});
	while (pq.size() != 0){
		auto [cur_cost, cur_node] = pq.top();
		pq.pop();
		if (reverse_visited[cur_node])
			continue;
		reverse_visited[cur_node] = true;
		for (int i = 0; i < reverse_g[cur_node].size(); i++) {
			auto [next_cost, next_node] = reverse_g[cur_node][i];
			if (!reverse_visited[next_node] && reverse_dp[next_node] > cur_cost + next_cost){
				reverse_dp[next_node] = cur_cost + next_cost;
				pq.push({reverse_dp[next_node], next_node});
			}
		}
	}
	int sol = -1;
	for (int i = 1; i < n + 1; i++) 
		sol = max(sol, dp[i] + reverse_dp[i]);
	cout << sol;
	return (0);
}
