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
vector<vector<vector<int>>> dp;
int max_bits = (1 << 10) - 1;
int mod = 1000000000;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	//length, end_num, use_number_bits
	dp.resize(n + 1, vector<vector<int>>(10, vector<int>(max_bits + 1, 0)));
	//init length 1
	for (int i = 1; i < 10; i++)
		dp[1][i][(1 << i)] = 1;
	//make dp from line len 2
	for (int i = 2; i < n + 1; i++){
		for (int end_num = 0; end_num < 10; end_num++) {
			int left_num = end_num - 1;
			int right_num = end_num + 1;
			int on_bits = 1 << end_num;
			for (int use_bits = 0; use_bits <= max_bits; use_bits++) {
				if (left_num != -1){
					dp[i][end_num][use_bits | on_bits] += dp[i - 1][left_num][use_bits];
					dp[i][end_num][use_bits | on_bits] %= mod;
				}
				if (right_num != 10){
					dp[i][end_num][use_bits | on_bits] += dp[i - 1][right_num][use_bits];
					dp[i][end_num][use_bits | on_bits] %= mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[n][i][max_bits];
		ans %= mod;
	}
	cout << ans;
	return (0);
}

