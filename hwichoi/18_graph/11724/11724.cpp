#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <queue>

using namespace std;
int n, m;
vector<int> adj[1002];
bool vis[1002];
queue<int> Q;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		Q.push(i);
		vis[i] = 1;
		while (!Q.empty()) {
			int tmp = Q.front(); Q.pop();
			for (int j : adj[tmp]) {
				if (vis[j]) continue;
				vis[j] = 1;
				Q.push(j);
			}
		}
		ret++;
	}
	cout << ret << '\n';
	return (0);
}

