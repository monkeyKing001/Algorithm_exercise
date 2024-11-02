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
int info[100001][3];
int dp[3];
int prev_dp[3];
int min_dp[3];
int min_prev_dp[3];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> info[i][j];
		}
	}
	dp[0] = info[0][0];
	dp[1] = info[0][1];
	dp[2] = info[0][2];
	min_dp[0] = info[0][0];
	min_dp[1] = info[0][1];
	min_dp[2] = info[0][2];
	//max
	for (int i = 1; i < n; i++) {
		int cur_r = i;
		prev_dp[0] = dp[0];
		prev_dp[1] = dp[1];
		prev_dp[2] = dp[2];
		min_prev_dp[0] = min_dp[0];
		min_prev_dp[1] = min_dp[1];
		min_prev_dp[2] = min_dp[2];
		for (int j = 0; j < 3; j++) {
			int cur_c = j, left_c = j - 1, right_c = j + 1;
			int cur_info = info[cur_r][cur_c];
			dp[cur_c] = prev_dp[cur_c];
			min_dp[cur_c] = min_prev_dp[cur_c];
			if (left_c >= 0){
				dp[cur_c] = max(prev_dp[left_c], dp[cur_c]);
				min_dp[cur_c] = min(min_prev_dp[left_c], min_dp[cur_c]);
			}
			if (right_c < 3){
				dp[cur_c] = max(prev_dp[right_c], dp[cur_c]);
				min_dp[cur_c] = min(min_prev_dp[right_c], min_dp[cur_c]);
			}
			dp[cur_c] += cur_info;
			min_dp[cur_c] += cur_info;
		}
	}
	int maxSol = 0;
	for (int i = 0; i < 3; i++) 
		maxSol = max(maxSol, dp[i]);
	int minSol = INT_MAX;
	for (int i = 0; i < 3; i++) 
		minSol = min(minSol, min_dp[i]);
	cout << maxSol << " " << minSol;
	return (0);
}

