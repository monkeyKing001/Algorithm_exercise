#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m, start;
int visited[1001];
vector <set <int> > adj_list(1001);
stack <int> s;
queue <int> q;

void dfs(int cur)
{
	if (visited[cur])
		return ;
	visited[cur] = 1;
	cout << cur << " ";
	for (set <int>::iterator it = adj_list[cur].begin(); it != adj_list[cur].end(); it++)
	{
		if (visited[*it])
			continue ;
		dfs(*it);	
	}
	 /* for (vector <set <int> >::iterator it = adj_list[cur].begin(); it != adj_list[cur].end(); it++) */
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
//		adj_list[u].push(v);
//		adj_list[v].push(u);
		adj_list[u].insert(v);
		adj_list[v].insert(u);
	}
	//dfs
	s.push(start);
	dfs(start);
	cout << "\n";
	//bfs
	fill_n(visited, 1001, 0);
	q.push(start);
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (visited[cur])
			continue ;
		visited[cur] = 1;
//		cout << "visiting " << cur << "\n";
		cout << cur << " ";
		for (set<int >::iterator it = adj_list[cur].begin(); it != adj_list[cur].end(); it++)
			q.push(*it);
	}
	
	return (0);
}

