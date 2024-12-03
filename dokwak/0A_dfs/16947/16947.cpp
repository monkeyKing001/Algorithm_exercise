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

vector<vector<int>> g;
vector<int> p (3001, -1);
vector<bool> cycle_flag;
vector<bool> visited_g;

int find_p(int u){
	if (p[u] == -1)
		return (u);
	p[u] = find_p(p[u]);
	return (p[u]);
}

void union_(int u, int v){
	int p_u = find_p(u);
	int p_v = find_p(v);
	if (p_v < p_u){
		int temp = p_u;
		p_u = p_v;
		p_v = temp;
	}
	p[p_v] = p_u;
}

bool cycle_find(int cur, int prev, int start){
//	cout << "\nvisiting cur, prev : " << cur << ", " << prev; 
	visited_g[cur] = true;
	for (int i = 0; i < g[cur].size() && !cycle_flag[cur]; i++) {
		int next = g[cur][i];
		if (next == prev)
			continue;
		//not visited
//		cout << "\nchecking next : " << next;
		if (!visited_g[next])
			cycle_flag[cur] = cycle_find(next, cur, start);
		else
			cycle_flag[cur] = true;
	}
//	cout << "\nEnd of traversing. cycle flag of " << cur << " : " << cycle_flag[cur];
	visited_g[cur] = false;
	return (cycle_flag[cur]);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n + 1);
	cycle_flag.resize(n + 1 ,false);
	visited_g.resize(n + 1, false);
	int cycle_start = -1;
	int cycle_parent = -1;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		int p_u = find_p(u);
		int p_v = find_p(v);
		if (p_u == p_v)
			cycle_start = u;
		else
			union_(u, v);
	}
//	cout << "\ncycle_start : " << cycle_start;
	cycle_find(cycle_start, -1, cycle_start);
	vector<int> ans(n + 1, 0);
	for (int i = 1; i < n + 1; i++) {
		int start = i;
		if (cycle_flag[start])
			continue;
		queue<pair<int, int>> q;
		vector<bool> visited(n + 1, false);
		q.push({start, 0});
		visited[start] = true;
		while (!q.empty()){
			pair<int, int> info = q.front();
			q.pop();
			int cur = info.first;
			int cur_step = info.second;
			for (int j = 0; j < g[cur].size(); j++){
				int next = g[cur][j];
				int next_step = cur_step + 1;
				if (cycle_flag[next]){
					ans[start] = next_step;
					//clear queue
					q = queue<pair<int, int>>();
					break;
				}
				if (!visited[next]) {
					visited[next] = true;
					q.push({next, next_step});
				}
			}
		}
	}
	for (int i = 1; i < n + 1; i++) 
		cout << ans[i] << " ";
	return (0);
}
