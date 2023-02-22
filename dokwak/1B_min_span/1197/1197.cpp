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
vector <tuple <int, int, int> > edge;
int group[100005];
int smae_group(int v1, int v2)
{
	if (group[v1] == group[v2])
		return (1);
	int temp_v1 = min(v1, v2);
	int temp_v2 = max(v1, v2);
	group[temp_v2] = temp_v1;
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
	sort(edge.begin(), edge.begin() + e);	
	for (int i = 0; i < e; ++i) {
		tie(v1, v2, cost) = edge[i];
	}
	return (0);
}

