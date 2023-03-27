#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
vector <vector <int>> g(101);
int visited[101];
int vir[101];
int vir_num = 0;
int n;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int r;
	cin >> r;
	for (int i = 0; i < r; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	queue <int> q;
	q.push(1);
	vir[1] = 1;
	while (q.size())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < g[cur].size(); i++)
		{
			int next_v = g[cur][i];
			if (!vir[next_v])
			{
				vir[next_v] = 1;
				q.push(next_v);
				vir_num++;
			}
		}
	}
	cout << vir_num;
	return (0);
}

