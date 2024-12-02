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
int max_cost = 16'111'111;

vector<vector<int>> g;
vector<vector<int>> dp;
int all_visited_bits = 0;
int start = 0;

int TSP(int cur, int visited_bits){
	if (visited_bits == all_visited_bits)
		return (dp[cur][start]);
	if (dp[cur][visited_bits] != -1)
		return(dp[cur][visited_bits]);
	dp[cur][visited_bits] = max_cost;
	int cur_visited_bits = visited_bits | (1 << cur);
	for (int i = 0; i < n; i++) {
		int next = i;
		int next_bit = 1 << i;
		if (next != cur && !(next_bit & visited_bits)){
			dp[cur][visited_bits] = min(dp[cur][visited_bits], TSP(next, next_bit | cur_visited_bits)) + g[cur][next];
		}
	}
	return (dp[cur][visited_bits]);
}

int	main(int argc, char **argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	all_visited_bits = (1 << n) - 1;
    g.resize(n, vector<int>(n));  // Resize and initialize the cost matrix
    dp.resize(n, vector<int>(all_visited_bits + 1, -1));  // DP table to store results
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
			if (i != j && g[i][j] == 0)
				g[i][j] = max_cost;
		}
	}
	int sol = TSP(start, 0);
	cout << sol;
	return (0);
}

