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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int dp[n + 1][10];
	int mod = 10007;
	for (int i = 0; i < n + 1; i++) {
		fill_n(dp[i], 10, 0);
	}
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mod;
			}
		}
	}
	int sol = 0;
	for (int i = 0; i < 10; i++) {
		sol += dp[n][i];
		sol %= mod;
	}
	cout << sol;
	return (0);
}

