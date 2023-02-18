#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
//#include <bits/stdc++.h>
#include <queue>

using namespace std;
int n;
vector <int> adj_list[100001];
queue <int> q;
int p[100001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}
	int start = 1;
	q.push(start);
	while (!q.empty())
	{
		int current = q.front();
		q.pop();
//		cout << "visiting : " << current << "\n";
		for (int i = 0; i < adj_list[current].size(); ++i)
		{
			int child = adj_list[current][i];
			if (p[child])
				continue ;
			p[child] = current;
			q.push(adj_list[current][i]);	
		}
	}
	for (int i = 2; i <= n; ++i) {
		cout << p[i] << "\n";
	}
	return (0);
}
