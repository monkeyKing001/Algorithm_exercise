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
int startPoint, endPoint;

bool possible(vector<map<int, int>> &g, int w){
	bool visited[n + 1];
	queue<int> q;
	fill_n(visited, n + 1, 0);
	q.push(startPoint);
	visited[startPoint] = true;
//	cout << "trying : " << w << "\n";
	while (q.size() != 0){
		int cur = q.front();
//		cout << "cur : " << cur << "\n";
		q.pop();
		if (cur == endPoint)
			return (true);
		for (auto it = g[cur].begin(); it != g[cur].end(); it++){
			int to = it -> first;
			int limit = it -> second;
//			cout << "from, to, possible : " << cur << ", " << to << ", " << limit << "\n";
			if (!visited[to] && limit >= w){
//				cout << "possible path\n";
				visited[to] = true;
				q.push(to);
			}
		}
	}
	return (false);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<map<int, int>> g;
	for (int i = 0; i < n + 1; i++) {
		map<int, int> gi;
		g.push_back(gi);
	}
	int l = 1;
	int r = 0;
	for (int i = 0; i < m; i++) {
		int u, v, limit;
		cin >> u >> v >> limit;
		r = max(r, limit);
		if (g[u].find(v) == g[u].end() || (g[u].find(v) != g[u].end() && g[u][v] < limit)){
			g[u][v] = limit;
			g[v][u] = limit;
//			cout << u << " <-> " << v <<  " : " << limit << "\n";
		}
	}
	cin >> startPoint >> endPoint;
	int sol = -1;
	while (l <= r){
		int mid = (l + r) / 2;
		//cout << "trying : " << mid << "\n";
		//try bigger
		if (possible(g, mid)){
			sol = mid;
			l = mid + 1;
		}
		//fail, try smaller
		else
			r = mid - 1;
	}
	cout << sol;
	return (0);
}

