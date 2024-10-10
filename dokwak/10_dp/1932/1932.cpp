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
int dr[2] = {1, 1};
int dc[2] = {0, 1};


int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<vector<int>> triangle(n, vector<int> (n, 0));
	vector<vector<int>> dp(n, vector<int> (n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
				cin >> triangle[i][j];
//				cout << triangle[i][j] << " "; 
		}
//		cout << "\n";
	}
	int sol = 0;
	dp[0][0] = triangle[0][0];
	for (int i = 0; i < n - 1; i++) {
		int cur_r = i;
		for (int j = 0; j < i + 1; j++) {
			int cur_c = j;
//			cout << dp[i][j] << " ";
			for (int d_i = 0; d_i < 2; d_i++) {
				int next_r = cur_r + dr[d_i];
				int next_c = cur_c + dc[d_i];
				dp[next_r][next_c] = max(dp[next_r][next_c], dp[cur_r][cur_c] + triangle[next_r][next_c]);
			}
		}
//		cout << "\n";
	}
	for (int i = 0; i < n; i++) {
		sol = max(sol, dp[n - 1][i]);
	}
	cout << sol;
	return (0);
}

