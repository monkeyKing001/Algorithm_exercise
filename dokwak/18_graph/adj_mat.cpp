#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int adj_mat[10][10];
int v, e;
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		adj_mat[u][v] = 1;
		adj_mat[v][u] = 1;//undirected graph
	}
	return (0);
}

