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
vector<vector<int>> g; 
vector<int> indegree_count;
queue<int> q;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	g.resize(n + 1, vector<int>(0));
	indegree_count.resize(n + 1, 0);
	vector<int> line;
	for (int i = 0; i < m; i++) {
		int out_node, in_node;
		cin >> out_node >> in_node;
		indegree_count[in_node]++;
		g[out_node].push_back(in_node);
	}
	for (int i = 1; i < n + 1; i++) {
		if (indegree_count[i] == 0)
			q.push(i);
	}
	while (q.size() != 0){
		int cur_node = q.front();
		line.push_back(cur_node);
		q.pop();
		for (int i = 0; i < g[cur_node].size(); i++) {
			int next = g[cur_node][i];
			indegree_count[next]--;
			if (indegree_count[next] == 0)
				q.push(next);
		}
	}
	for (int i = 0; i < line.size(); i++) 
		cout << line[i] << " ";
	return (0);
}

