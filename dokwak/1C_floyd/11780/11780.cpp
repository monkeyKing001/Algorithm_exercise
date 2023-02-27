#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#define MAX_COST 1000000000

using namespace std;
long long v1, v2, cost;
int n, m;
long long adj_mat[200][200];
int next_path[200][200];
int step_count[200][200];

int	get_path(int v1, int v2, int &count)
{
	return (0);
}

int get_count(int v1, int v2)
{
	return (0);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			adj_mat[i+1][j+1] = MAX_COST;
			next_path[i+1][j+1] = 0;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> v1 >> v2 >> cost;
		if (adj_mat[v1][v2] > cost)
		{
			adj_mat[v1][v2] = cost;
			next_path[v1][v2] = v1;
		}

		adj_mat[v1][v2] = min(cost, adj_mat[v1][v2]);
	}
	for (int bridge = 1; bridge <= n; ++bridge)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				v1 = i + 1;
				v2 = j + 1;
				if (adj_mat[v1][v2] > adj_mat[v1][bridge] + adj_mat[bridge][v2])
				{
					adj_mat[v1][v2] = adj_mat[v1][bridge] + adj_mat[bridge][v2];
					next_path[v1][v2] = bridge;
					step_count[v1][v2]++;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != j && adj_mat[i+1][j+1] != MAX_COST)
				cout << adj_mat[i+1][j+1] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
	for (int i = 0; i < n; ++i)
	{
		v1 = i+1;
		for (int j = 0; j < n; ++j)
		{
			v2 = j + 1;
			int count = 0;
			get_count(v1, v2);
			get_path(v1, v2, count);
		}
	}
	return (0);
}

