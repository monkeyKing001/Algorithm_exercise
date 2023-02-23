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

int find_parent(int v1)
{
	if (p[v1] < 0)
		return (v1);
	p[v1] = find_parent(p[v1]);
	return (p[v1]);
}

bool comp_tup(tuple<int, int, int> t1, tuple <int, int, int>t2)
{
	return (get<2>(t1) < get<2>(t2));
}

int is_same_group(int v1, int v2)
{
	int v1_g, v2_g;
	int temp1, temp2;
	v1_g = find_parent(v1);
	v2_g = find_parent(v2);
	temp1 = v1;
	temp2 = v2;
	if (v1_g == v2_g)
		return (1);
	else
	{
//		if (v2_g < v1_g)
//			swap(temp1, temp2);
//		p[temp2] = find_parent(temp1);
		if (v2_g < v1_g)
			swap(v2_g, v1_g);
		p[v2_g] = v1_g;
//		cout << "now "
//			<< temp2
//			<< "'s parents is "
//			<< p[temp2]
//			<< "\n";
	}
	return (0);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2 >> cost;
		edge.push_back(make_tuple(v1, v2, cost));
	}
	//sort
	fill_n(p, 100005, -1);
	sort(edge.begin(), edge.begin() + e, comp_tup);	
	for (int i = 0; i < e; i++) {
		int v1, v2, cost;
		tie(v1, v2, cost) = edge[i];
		if (is_same_group(v1, v2))
			continue;
//		cout
//			<< v1
//			<< ", "
//			<< v2
//			<< " is now same group\n";
		total_edge++;
		total_cost+= cost;
		if (total_edge == v - 1)
			break ;
	}
	for (int i = 1; i <= v; ++i) {
		cout << i << "'s parent : " << p[i] << "\n";
	}
	cout << total_cost;
	return (0);
}
