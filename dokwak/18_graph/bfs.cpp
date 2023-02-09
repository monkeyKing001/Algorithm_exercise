#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n;
int v, e;
vector <vector <int> > adj;
queue <int> next_visit;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	vector <int> visited(v + 1);
	fill_n(visited.begin(), v + 1, 0);
	for (int i = 0; i < v + 1; i++)
	{
		vector <int> temp;
		adj.push_back(temp);
	}
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); //undirected
	}
	for (int i = 1; i < v + 1; i++)
	{
		if (!visited[i])
		{
			cout << "bfs start from " << i << "\n";
			next_visit.push(i);
			while (!next_visit.empty())
			{
				int current = next_visit.front();
				if (visited[current])
				{
					next_visit.pop();
					if (!next_visit.empty())
						current = next_visit.front();
					continue ;
				}
				cout << "visiting current : " << current << "\n";
				visited[current] = 1;
				next_visit.pop();
				for (int j = 0; j < adj[current].size(); j++)
				{
					if (!visited[adj[current][j]])
					{
						cout << "pushing queue " << adj[current][j] << "\n";
						next_visit.push(adj[current][j]);
					}
				}
				if (!next_visit.empty())
					current = next_visit.front();
			}
		}
			//bfs
		else
			continue ;
	}
	return (0);
}

