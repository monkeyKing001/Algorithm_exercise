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
int max_cost = 11000 * 22;
int max_job_bits = 0;
vector<vector<int> > info;
vector<vector<int> > dp;

int TSP(int cur, int visited_bits) {
	if (visited_bits == max_job_bits)
		return (0);
	if (dp[cur][visited_bits] != -1)
		return (dp[cur][visited_bits]);
	dp[cur][visited_bits] = max_cost;
	for (int i = 0; i < n; i++) {
		int job = i;
		int job_visited_bits = 1 << job;
		if (visited_bits & job_visited_bits)
			continue;
		dp[cur][visited_bits] = min(dp[cur][visited_bits], TSP(cur + 1, visited_bits | job_visited_bits) + info[cur][job]);
	}
	return (dp[cur][visited_bits]);
}

int	main(int argc, char **argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin  >> n;
	max_job_bits = (1 << n) - 1;
	info.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> info[i][j];
		}
	}
	dp.resize(n, vector<int>(max_job_bits, -1));
	int sol = INT_MAX;
	sol = TSP(0, 0);
	cout << sol;
	return (0);
}

