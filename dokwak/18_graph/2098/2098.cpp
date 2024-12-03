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
int max_visited_bits;
int max_cost = 16111000;

vector<vector<int>> g;
vector<vector<int>> cost;

int TSP(int cur_node, int visited_bits){
	if (visited_bits == max_visited_bits)
		return (g[cur_node][0]);
	//if calculated before, return the result
	if (cost[cur_node][visited_bits] != -1)
		return (cost[cur_node][visited_bits]);
	cost[cur_node][visited_bits] = max_cost;
	for (int i = 0; i < n; i++){
		int next_node = i;
		if (g[cur_node][next_node] == 0)
			continue;
		int next_visited_bits = (1 << next_node) | visited_bits;
		if (next_visited_bits == visited_bits)
			continue;
		cost[cur_node][visited_bits] = min(cost[cur_node][visited_bits], TSP(next_node, next_visited_bits) + g[cur_node][next_node]);
	}
	return(cost[cur_node][visited_bits]);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	max_visited_bits = (1 << n) - 1;
	g.resize(n, vector<int>(n, 0));
	cost.resize(n, vector<int>(max_visited_bits, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			if (g[i][j] == 0)
				g[i][j] = max_cost;
		}
	}
	int sol = TSP(0, 1);
	cout << sol;
	return (0);
}

