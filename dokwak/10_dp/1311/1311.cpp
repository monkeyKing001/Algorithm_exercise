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
int max_bits = 0;
int max_cost = 200000;
vector<vector<int>> g;
vector<vector<int>> cost;

int TSP(int cur, int visited_bits){
	if (visited_bits == max_bits)
		return (0);
	if (cost[cur][visited_bits] != -1)
		return (cost[cur][visited_bits]);
	cost[cur][visited_bits] = max_cost;
	for (int job = 0; job < n; job++) {
		int job_bit = 1 << job;
		if (job_bit & visited_bits)
			continue;
		cost[cur][visited_bits] = min(cost[cur][visited_bits], TSP(cur + 1, job_bit | visited_bits) + g[cur][job]);
	}
	return (cost[cur][visited_bits]);
}

int	main(int argc, char **argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n, vector<int>(n, 0));
	cost.resize(n, vector<int>(1 << n, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	max_bits = (1 << n) - 1;
	int sol = TSP(0, 0);
	cout << sol;
	return (0);
}

