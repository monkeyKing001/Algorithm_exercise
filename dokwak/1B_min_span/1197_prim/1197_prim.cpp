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

struct comp_edge_cost{
	bool operator()(int *e1, int *e2)
	{
		return (e1[2] > e2[2]);
	}
};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	set <int> in_mst;
	vector <vector <int *>> adj_list(n + 1);
	vector <vector <pair<int, int>>> adj2(n + 1);
	priority_queue<int *, vector<int*>, comp_edge_cost> pq;
	priority_queue<
		pair<int, int>, 
		vector <pair<int, int>>, 
		greater<pair <int, int>>
			> pq2;
	int start = 1;
	for (int i = 0; i < m; i++)
	{
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;
		int *e1 = new int[3];
		int *e2 = new int[3];
		e1[0] = cost;
		e1[1] = v2;
		e1[2] = v1;
		e2[0] = cost;
		e2[1] = v1;
		e2[2] = v2;
		adj_list[v1].push_back(e1);
		adj_list[v2].push_back(e2);
		adj2[v1].push_back(make_pair(cost, v2));
		adj2[v2].push_back(make_pair(cost, v1));
		if (v1 == start)
		{
			pq.push(e1);
			pq2.push(make_pair(cost, v2));
		}
	}
	int mst_w = 0;
	in_mst.insert(1);
	while (pq2.size())
	{
		int cur, connected_v, cost;
		cost = pq2.top().first;
		connected_v = pq2.top().second;
		pq2.pop();
		if (in_mst.find(connected_v) != in_mst.end())
			continue ;
		in_mst.insert(connected_v);
		mst_w += cost;
		if (in_mst.size() == n)
			break;
		for (int i = 0; i < adj2[connected_v].size(); i++)
		{
			int next_v = adj2[connected_v][i].second;
			if (in_mst.find(next_v) != in_mst.end())
				continue ;
			pq2.push(adj2[connected_v][i]);
		}
	}
	cout << mst_w;
	return (0);
}
