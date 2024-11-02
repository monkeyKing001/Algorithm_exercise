#include <sys/resource.h>
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
int mod = 1000000009;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> dp(1000001, 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 1000001; i++){
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
		dp[i] += dp[i - 3];
		dp[i] %= mod;
	}
	cin >> n;
	for (int t_i = 0; t_i < n; t_i++) {
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}
	return (0);
}

