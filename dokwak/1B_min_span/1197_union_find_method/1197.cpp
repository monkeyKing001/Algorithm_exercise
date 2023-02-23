#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <tuple>
using namespace std;

int v, e;
int v1, v2, cost;
int total_edge, total_cost;
vector <tuple <int, int, int> > edge;
int p[100005];

int find_root(int v1)
{
	if (p[v1] < 0)
		return (v1);
	p[v1] = find_root(p[v1]);
	return (p[v1]);
}

bool comp_tup(tuple<int, int, int> t1, tuple <int, int, int>t2)
{
	return (get<2>(t1) < get<2>(t2));
}

int is_same_group(int v1, int v2)
{
	int v1_g, v2_g;
	v1_g = find_root(v1);
	v2_g = find_root(v2);
	if (v1_g == v2_g)
		return (1);
	else
	{
		if (v2_g < v1_g)
			swap(v1, v2);
		p[v2] = v1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		cin >> v1 >> v2 >> cost;
		edge.push_back(make_tuple(v1, v2, cost));
	}
	//sort
	fill_n(p, 100005, -1);
	sort(edge.begin(), edge.begin() + e, comp_tup);	
	for (int i = 0; i < e; ++i) {
		int v1, v2, cost;
		tie(v1, v2, cost) = edge[i];
		if (is_same_group(v1, v2))
			continue;
		total_edge++;
		total_cost+= cost;
		if (total_edge == v - 1)
			break ;
	}
	cout << total_cost;
	return (0);
}
