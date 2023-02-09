#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int v, e;
vector <int> adj[10];
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); //undirected graph
	}
	//without STL, dynamically;
	int temp_edge[e][2];
	int *deg = new int[v];
	int **adj_lst = new int*[v];
	fill_n(deg, v, 0);
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		temp_edge[i][0] = u;
		temp_edge[i][1] = v;
		deg[u]++;
		//undirected
		deg[v]++;
	}
	for (int i = 0; i < v; i++)
	{
		int col_n = deg[i];
		adj_lst[i] = new int[col_n];
	}
	for (int i = 0; i < e; i++)
	{
		int u, v;
		u = temp_edge[i][0];
		v = temp_edge[i][1];
		adj_lst[u][--deg[u]] = v;
		//undirected
		adj_lst[v][--deg[v]] = u;
	}
	return (0);
}

