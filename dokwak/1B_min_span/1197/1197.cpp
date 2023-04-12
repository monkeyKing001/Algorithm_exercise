#include <bits/stdc++.h>
using namespace std;

int v, e;
int parent[10001];

int find_parent(int v)
{
	if (parent[v] == 0)
		return v;
	else
		parent[v] = find_parent(parent[v]);
	return (parent[v]);
}

int is_same_group(int v1, int v2)
{
	return (find_parent(v1) == find_parent(v2));
}

void merge_group(int v1, int v2)
{
//	cout << v1 << "'s group is " << find_parent(v1) << "\n";
//	cout << v2 << "'s group is " << find_parent(v2) << "\n";
	if (is_same_group(v1, v2))
		return ;
	int smaller_g = min(find_parent(v1), find_parent(v2));
	if (smaller_g == find_parent(v2))
		swap(v1, v2);
	parent[find_parent(v2)] = smaller_g;
//	cout << "merging " << v1 << ", " << v2 << "\n";
//	cout << "now " << v2 << "'s group is " << parent[v2] << "\n";
}

bool comp_edge(int e1[3], int e2[3])
{
	return (e1[2] < e2[2]);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> v >> e;
	//int edges[100001][3];
	vector <int *> edges(e);
	for (int i = 0; i < e; i++)
	{
		int v1, v2, cost;
		int *edge = new int[3];
		cin >> v1 >> v2 >> cost;
		edge[0] = v1;
		edge[1] = v2;
		edge[2] = cost;
		edges[i] = edge;
	}
	sort(edges.begin(), edges.begin() + e, comp_edge);
//	for (int i = 0; i < e; i++)
//	{
//		cout << "edge from " << edges[i][0] << " to " << edges[i][1] << " with cost " << edges[i][2] << "\n";
//	}
	int count = 0;
	long long mst_w = 0;
	for (int i = 0; i < e; i++)
	{
		int v1, v2, cost;
		v1 = edges[i][0];
		v2 = edges[i][1];
		cost = edges[i][2];
		if (is_same_group(v1, v2))
			continue ;
		merge_group(v1, v2);
		count++;
		mst_w += cost;
		if (count == v - 1)
			break ;
	}
	cout << mst_w;
	return (0);
}
