#include <queue>
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
priority_queue<
				pair <int, int>,
				vector<pair <int, int>>,
				greater <pair<int, int>>
				> pq;

int cost_to_visit[200001];
vector <pair<int, int>> g[20001];
int start;
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n + 1; i++)
		cost_to_visit[i] = 20000001;
	cin >> start;
	cost_to_visit[start] = 0;
	for (int i = 0; i < m; i++)
	{
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;
		pair <int, int> edge = make_pair(cost, v2);
		g[v1].push_back(edge);
		if (v1 == start)
		{
			cost_to_visit[v2] = min(cost_to_visit[v2], cost);
			pq.push(edge);
		}
	}
	while(pq.size())
	{
		int connected_v, connected_cost;
		pair <int, int> edge = pq.top();
		pq.pop();
		connected_cost = edge.first;
		connected_v = edge.second;
		if (connected_cost != cost_to_visit[connected_v])
			continue ;
		for (int i = 0; i < g[connected_v].size(); i++)
		{
			int next_v, next_cost;
			next_v = g[connected_v][i].second;
			next_cost = g[connected_v][i].first;
			if (cost_to_visit[next_v] > connected_cost + next_cost)
			{
				cost_to_visit[next_v] = next_cost + connected_cost;
				pair <int, int> new_edge = make_pair(cost_to_visit[next_v], next_v);
				pq.push(new_edge);
			}
		}
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (cost_to_visit[i] == 20000001)
			cout << "INF\n";
		else
			cout << cost_to_visit[i] << "\n";
	}
	return (0);
}

