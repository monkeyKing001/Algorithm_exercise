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
string dfsPath;
string bfsPath;
void dfs(int cur, vector<set<int>> &g, vector<bool> &visited){
	if (visited[cur])
		return;
//	cout << "visiting : " << cur << "\n";
	string nextStr = to_string(cur);
	dfsPath += nextStr;
	dfsPath.push_back(' ');
	visited[cur] = true;
	set<int>::iterator it = g[cur].begin();
	while (it != g[cur].end()){
		int next = *it;
		if (!visited[next])
			dfs(next, g, visited);
		it++;
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> startPoint;
	vector<set<int>> g(n + 1);
	vector<bool> visitedDfs(n + 1, false);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	//dfs
	dfs(startPoint, g, visitedDfs);
	//bfs
	queue<int> q;
	vector<bool> visitedBfs(n + 1, false);
	q.push(startPoint);
	string nextStr = to_string(startPoint);
	bfsPath += nextStr;
	bfsPath.push_back(' ');
	visitedBfs[startPoint] = true;
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		set<int>::iterator it = g[cur].begin();
		while (it != g[cur].end()){
			int next = *it;
			if (!visitedBfs[next]){
				q.push(next);
				string nextStr = to_string(next);
				bfsPath += nextStr;
				bfsPath.push_back(' ');
				visitedBfs[next] = true;
			}
			it++;
		}
	}
	cout << dfsPath << "\n";
	cout << bfsPath << "\n";
	return (0);
}

