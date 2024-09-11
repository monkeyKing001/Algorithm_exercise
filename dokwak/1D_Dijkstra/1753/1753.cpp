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
int max_cost = 0;

struct custom_cmp{
	bool operator()(pair<int, int>bottom, pair<int, int>top){
		return (bottom.second > top.second);
	}
};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int v_count, e_count;
	cin >> v_count >> e_count;
	int start;
	cin >> start;
	vector<int> dp(v_count + 1, v_count * 11);
	max_cost = v_count * 11;
	vector<vector<pair<int, int>>> g(v_count + 1);
	for (int i = 0; i < v_count + 1; i++) 
		g[i].push_back({i, 0});
	for (int i = 0; i < e_count; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		g[u].push_back({v, cost});
	}
	std::priority_queue<pair<int, int>, vector<pair<int, int>>, custom_cmp> pq;
	int node_count = 0;
	pq.push({start, 0});
	while (pq.size() != 0){
		pair<int, int> info = pq.top();
		pq.pop();
		int cur_v = info.first;
		int cur_cost = info.second;
		for (auto it : g[cur_v]) {
			int next_v = it.first;
			int next_cost = it.second + cur_cost;
			if (dp[next_v] > next_cost){
				dp[next_v] = next_cost;
				pq.push({next_v, next_cost});
			}
		}
	}
	for (int i = 1; i < v_count + 1; i++) {
		if (dp[i] == max_cost)
			cout << "INF\n";
		else
			cout << dp[i] << "\n";
	}
	return (0);
}
