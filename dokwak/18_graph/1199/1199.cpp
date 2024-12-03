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

vector<unordered_map<int, int>> g;
vector<int> degree;
vector<bool> visited;

void Euiler(int cur, vector<int> &path){
	unordered_map<int, int> &edges = g[cur];
	while (!edges.empty()){
		int node = edges.begin() -> first;
		int num = edges.begin() -> second;
		g[cur][node]--;
		g[node][cur]--;
		if (g[cur][node] == 0)
			g[cur].erase(node);
		if (g[node][cur] == 0)
			g[node].erase(cur);
		Euiler(node, path);
	}
	path.push_back(cur);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n + 1);
	degree.resize(n + 1, 0);
    int total_count = 0;
	for (int i = 1; i < n + 1; i++) {
        int count = 0;
		for (int j = 1; j < n + 1; j++) {
			int connected = 0;
			cin >> connected;
            count += connected;
			if (connected && i < j){
				g[i][j] = connected;
				g[j][i] = connected;
			}
		}
        if (count % 2 != 0){
            cout << -1;
			return (0);
        }
        total_count += count;
	}
	vector<int> path;
    path.reserve(total_count);
	Euiler(1, path);
	for (int i = path.size() - 1; i > -1; i--) {
		cout << path[i] << " ";
	}
	return (0);
}

