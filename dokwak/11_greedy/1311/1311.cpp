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
int max_cost = 10000 * 22;

vector<vector<int>> info(20, vector<int>(20));
vector<vector<int>> dp(20, vector<int>(1 << 20, max_cost));

int TSP(int cur, int visited_bits) {
	if (visited_bits == max_bits)
		return 0;
	if (dp[cur][visited_bits] != max_cost)
		return (dp[cur][visited_bits]);
	int &ret = dp[cur][visited_bits];
	for (int i = 0; i < n; i++) {
		int job = i;
		int job_bits = (1 << job);
		if (visited_bits & job_bits)
			continue;
		dp[cur][visited_bits] = min(dp[cur][visited_bits], TSP(cur + 1, visited_bits | job_bits) + info[cur][job]);
	}
	return (ret);
}

int	main(int argc, char **argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	max_bits = (1 << n) - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> info[i][j];
		}
	}
	int sol = TSP(0, 0);
	cout << sol;
	return (0);
}

