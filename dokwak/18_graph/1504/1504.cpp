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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	long long g[n + 1][n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			g[i][j] = INT_MAX;	
			if (i == j)
				g[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		long long cost;
		cin >> v1 >> v2 >> cost;
		g[v1][v2] = min(g[v1][v2], cost);
		g[v2][v1] = min(g[v2][v1], cost);
	}
	for (int bridge = 0; bridge < n + 1; bridge++)
	{
		for (int start = 0; start < n + 1; start++)
		{
			for (int end = 0; end < n + 1; end++)
			{
				if (g[start][end] > g[start][bridge] + g[bridge][end])
				{
					g[start][end] = g[start][bridge] + g[bridge][end];
					g[end][start] = g[start][end];

				}
			}
		}
	}
	//impossible case
	int v1, v2;
	long sol = 0;
	cin >> v1 >> v2;
	if (g[1][v1] == INT_MAX || g[1][v2] == INT_MAX || g[1][n] == INT_MAX)
		sol = -1;
	else
		sol = min(g[1][v1] + g[v1][v2] + g[v2][n], g[1][v2] + g[v2][v1] + g[v1][n]);
	cout << sol;
	return (0);
}
