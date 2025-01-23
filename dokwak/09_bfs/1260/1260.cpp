#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m, startPoint;
string dfsPath = "";
string bfsPath = "";
vector<set<int>> g;
vector<bool> visitedDfs;
vector<bool> visitedBfs;

void dfs(int node){
  dfsPath += (to_string(node) + " "); 
  visitedDfs[node] = true;
  for (auto child : g[node]){
    if (!visitedDfs[child]) dfs(child);
  }
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> startPoint;
  g.resize(n + 1);
  bfsPath.reserve(min(n * 4, m * 4));
  dfsPath.reserve(min(n * 4, m * 4));
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}

	//dfs

  visitedDfs.resize(n + 1, false);
  dfs(startPoint);

	//bfs
  visitedBfs.resize(n + 1, false);
	queue<int> q;
	q.push(startPoint);
  visitedBfs[startPoint] = true;
  while (q.size()){
    int cur = q.front();
    q.pop();
    bfsPath += to_string(cur) + " ";
    for (auto child : g[cur]){
      if (!visitedBfs[child]){
        visitedBfs[child] = true;
        q.push(child);
      }
    }
  }
	cout << dfsPath << "\n";
	cout << bfsPath << "\n";
	return (0);
}

