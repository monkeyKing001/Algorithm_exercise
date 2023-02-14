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
vector <vector <int> > adj_list(1100);
int visited[1100];
int sol = 0;
queue <int> q;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
//			cout << "start from " << i << "\n";
			q.push(i);
			//bfs start!!
			sol++;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				if (visited[cur])
					continue;
				visited[cur] = 1;
//				cout << "visiting " << cur << "\n";
				for (int i = 0; i < adj_list[cur].size(); i++)
					q.push(adj_list[cur][i]);
			}
		}
	}
	cout << sol << "\n";
	return (0);
}

