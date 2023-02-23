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
int group[100005];
int same_group(int v1, int v2)
{
	if (group[v1] == group[v2])
		return (1);
	int merge_group = min(group[v1], group[v2]);
	int temp_g1 = group[v1];
	int temp_g2 = group[v2];
	for (int i = 1; i <= v; i++)
	{
		if (group[i] == temp_g1 || group[i] == temp_g2)
			group[i] = merge_group;
	}
//	cout << v1 << ", " << v2 << " is now same group as " << merge_group << "\n";
	return (0);
}

bool comp_tup(tuple<int, int, int> t1, tuple <int, int, int>t2)
{
	return (get<2>(t1) < get<2>(t2));
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
	sort(edge.begin(), edge.begin() + e, comp_tup);	
	//group init
	for (int i = 1; i <= v; i++) {
		group[i] = i;
	}
	for (int i = 0; i < e; ++i) {
		tie(v1, v2, cost) = edge[i];
		if (same_group(v1, v2))
			continue ;
		else
		{
			total_cost += cost;
			total_edge++;
//			cout << "grouping v1, v2 :" << v1 << ", " << v2 << "\n";
//			cout << "total_cost : " << total_cost << "\n";
		}
		if (total_edge == v - 1)
			break; 

	}
//	for (int i = 1; i <= v; ++i) {
//		cout << i <<"'s group is " << group[i] << "\n";
//	}
	cout << total_cost;
	return (0);
}
