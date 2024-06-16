#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int n, m;
#define MAX 100000000
#define ll long long

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<vector<ll>> g(n + 1, vector<ll> (n + 1 ,MAX));
	for (int i = 0; i < m; i++) {
		ll u, v, cost;
		cin >> u >> v >> cost;
		g[u][v] = min(g[u][v], cost);
	}
	for (int i = 1; i < n + 1; i++) {
		ll bridge = i;
		g[bridge][bridge] = 0;
		for (int j = 1; j < n + 1; j++) {
			ll start = j;
			for (int k = 1; k < n + 1; k++) {
				ll end = k;
				g[start][end] = min(g[start][bridge] + g[bridge][end], g[start][end]);
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (g[i][j] == MAX)
				cout << "0";
			else
				cout << g[i][j];
			cout << " ";
		}
		cout <<"\n";
	}
	return (0);
}

