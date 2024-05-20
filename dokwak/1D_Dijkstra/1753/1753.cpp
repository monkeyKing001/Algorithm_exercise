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
int maxCost = 3300000;

struct cmp{
	bool operator()(pair<int, int> bottom, pair<int, int>top){
		return (bottom.second > top.second);
	}
};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int start;
	cin >> n >> m >> start;;
	vector<vector<pair<int, int>>> g(n + 1);
	vector<int> costDp(n + 1, maxCost);
	costDp[start] = 0;
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		g[u].push_back({v, cost});
	}
	priority_queue<pair<int ,int>, vector<pair<int, int>>, cmp> pq;
//	for (int i = 0; i < g[start].size(); i++){
//		int to = g[start][i].first;
//		int cost = g[start][i].second;
//		//costDp[to] = min(costDp[to], cost);
//		pq.push({g[start][i].first, g[start][i].second});
//	}
	pq.push({start, costDp[start]});
	while (pq.size() != 0){
		int curNode = pq.top().first;
		int curCost = pq.top().second;
		pq.pop();
		for (int i = 0; i < g[curNode].size(); i++){
			int nextNode = g[curNode][i].first;
			int nextCost = costDp[curNode] + g[curNode][i].second;
			if (costDp[nextNode] > nextCost){
				costDp[nextNode] = nextCost;
				pq.push({nextNode, nextCost});
			}
		}
	}
	for (int i = 1; i <= n ; i++) {
		if (costDp[i] == maxCost)
			cout << "INF\n";
		else
			cout << to_string(costDp[i]) + "\n";
	}
	return (0);
}
