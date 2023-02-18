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
queue <int> q;
vector <int> adj_list[100];
int p[100];
int d[100];

void dfs(int cur, int parent)
{
	cout << cur << " "; 
	for (int i = 0; i < adj_list[cur].size(); i++)
	{
		int connected = adj_list[cur][i];
		if (parent == connected)
			continue;
		p[connected] = cur; 
		dfs(connected, cur);
	}
}

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
	int start;
	cin >> start;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
//		cout << "depth : " << d[cur] << "\n";
		for (int i = 0; i < adj_list[cur].size(); i++)
		{
			int child = adj_list[cur][i];
			if (child == p[cur])
			{
//				cout << "I am " << cur;
//				cout << " oh I met my parent" << child << ", " << p[cur];
				continue ;
			}
			p[child] = cur;
			d[child] = d[cur] + 1;
			q.push(child);
		}
	}
	fill_n(p, 100, 0);
	cout << "\n";
	dfs(start, p[start]);
	cout << "\n";
	return (0);
}
