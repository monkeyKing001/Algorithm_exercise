#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <bits/stdc++.h>
//#define INT_MAX 2000000000
using namespace std;

vector<int> solution(int n, vector<vector<int> > roads, vector<int> sources, int destination) {
	vector <int> ans;
	long long min_cost[n + 1];
	vector <vector <int>> given_path(100001);
	for (int i = 0; i < n + 1; i++)
		min_cost[i] = INT_MAX;
	//input
	queue <int> q;
	for (int i = 0; i < roads.size(); i++)
	{
		int v1 = roads[i][0];
		int v2 = roads[i][1];
		given_path[v1].push_back(v2);
		given_path[v2].push_back(v1);
		if (v1 == destination)
		{
			min_cost[v2] = 1;
			q.push(v2);
		}
		else if (v2 == destination)
		{
			min_cost[v1] = 1;
			q.push(v1);
		}
		else 
		{
			given_path[v1].push_back(v2);
			given_path[v2].push_back(v1);
		}
	}
	while (q.size())
	{
		int c_v = q.front();
		int cur_step = min_cost[c_v];
		q.pop();
		for (int i = 1; i < given_path[c_v].size(); i++)
		{
			int n_v = given_path[c_v][i];
			if (min_cost[n_v] == INT_MAX)
			{
				q.push(n_v);
				min_cost[n_v] = cur_step + 1;
			}
		}
	}
	for (int i = 0; i < sources.size(); i++)
	{
		if (sources[i] == destination)
			ans.push_back(0);
		else if (min_cost[sources[i]] == INT_MAX)
			ans.push_back(-1);
		else
			ans.push_back(min_cost[sources[i]]);
	}
	return (ans);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <vector <int> > roads;
	vector <int> srcs;
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		vector <int> temp;
		temp.push_back(v1);
		temp.push_back(v2);
		roads.push_back(temp);
	}
	int src;
	cin >> src;
	for (int i = 0; i < src; i++)
	{
		int temp;
		cin >> temp;
		srcs.push_back(temp);
	}
	int dest;
	cin >> dest;
	const vector <int> &ans = solution(n, roads, srcs, dest);
	for (int i = 0; i < srcs.size(); i++)
	{
		cout << ans[i] << " ";
	}
	return (0);
}
