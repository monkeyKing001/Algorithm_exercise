#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> dp(51, 0);
	int mod = 1e9 + 7;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < 51; i++){
		dp[i] = dp[i - 1] + dp[i - 2] + 1;
		dp[i] %= mod;
	}
	cout << dp[n];
	return (0);
}

