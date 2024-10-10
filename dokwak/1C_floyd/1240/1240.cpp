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
int max_cost = 1110000;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin  >> n >> m;
	vector<vector<int>> g(n + 1, vector<int> (n + 1, max_cost));
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (i == j )
				g[i][j] = 0;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		g[u][v] = min(g[u][v], cost);
		g[v][u] = min(g[v][u], cost);
	}
	for (int bridge_i = 0; bridge_i < n + 1; bridge_i++) {
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n + 1; j++) {
				g[i][j] = min(g[i][j], g[i][bridge_i] + g[bridge_i][j]);
			}
		}
	}
//	for (int i = 0; i < n + 1; i++) {
//		for (int j = 0; j < n + 1; j++) {
//			cout << g[i][j] << " ";
//		}
//		cout << "\n";
//	}
	//query
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		cout << g[u][v] << "\n";
	}
	return (0);
}

