#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<vector<ll>> dp(31, vector<ll>(31, 0));
	dp[0][0] = 1;
	for (int i = 1; i < 31; i++){
		for (int j = 0; j <= i; j++) {
			if (j != 0)
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = 1;
		}
	}
	int num;
	cin >> num;
	while (num != 0){
		cout << dp[num][num] << "\n";
		cin >> num;
	}
	return (0);
}

