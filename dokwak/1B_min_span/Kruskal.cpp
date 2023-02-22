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
tuple <int, int, int> edge[100005];

int is_same_group(int v1, int v2)
{
	return (1);
}


int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cost, v1, v2;
	int tree_edge = 0;
	//input
	//sort
	//pick the smallest cost edge
	for (int i = 0; i < e; ++i)
	{
		tie(cost, v1, v2) = edge[i];
		//if (is_same_group(v1, v2))
		if (is_same_group(get<1>(edge[i]), get<2>(edge[i])))
			continue ;
		tree_edge++;
		if (tree_edge == v - 1)
			break;
	}
	return (0);
}

