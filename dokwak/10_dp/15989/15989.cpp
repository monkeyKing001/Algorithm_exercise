#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	vector<vector<int>> dp(10001, vector<int>(4, 0));
	dp[1][1] = 1;
	dp[2][1] = 1, dp[2][2] = 1;
	dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;
	for (int i = 4; i < 10001; i++){
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= j; k++){
				dp[i][j] += dp[i - j][k];
			}
		}
	}
	for (int t_i = 0; t_i < T; t_i++) {
		int num;
		cin >> num;
		cout << dp[num][1] + dp[num][2] + dp[num][3] << "\n";
	}
	return (0);
}

