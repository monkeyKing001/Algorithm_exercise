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
int maxCost = 100001;
struct cmp{
	bool operator() (vector<int> bottom, vector<int>top){
		return (top[2] < bottom[2]);
	}
};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> x;
	vector<vector<pair<int, int>>> g(n + 1);
	vector<vector<pair<int, int>>> reverseG(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		g[u].push_back({v, cost});
		reverseG[v].push_back({u, cost});
	}
	int costForward[n + 1];
	int costBackward[n + 1];
	fill_n(costForward, n + 1, maxCost);
	fill_n(costBackward, n + 1, maxCost);
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	int repeatIterNum = 2, forward = 0, backward = 1;
	for (int i = 0; i < repeatIterNum; i++) {
		int *costP = (i == forward) ? costForward : costBackward;
		vector<vector<pair<int, int>>> &graph = (i == forward) ? g : reverseG;
		costP[x] = 0;
		vector<int> init = {0, x, 0};
		pq.push(init);
		while (!pq.empty()){
			vector<int> nowInfo = pq.top();
			pq.pop();
			int nowNode = nowInfo[1];
			int nowCost = nowInfo[2];
			if (costP[nowNode] < nowCost)
				continue;
			for (int j = 0; j < graph[nowNode].size(); j++) {
				int nextNode = graph[nowNode][j].first;
				int nextCost = graph[nowNode][j].second + nowCost;
				if (costP[nextNode] > nextCost){
					costP[nextNode] = nextCost;
					vector<int> nextInfo = {x, nextNode, nextCost};
					pq.push(nextInfo);
				}
			}
		}
	}
	int sol = 0;
	for (int i = 1; i < n + 1; i++) {
		sol = max(sol, costForward[i] + costBackward[i]);
	}
	cout << sol;
	return (0);
}
