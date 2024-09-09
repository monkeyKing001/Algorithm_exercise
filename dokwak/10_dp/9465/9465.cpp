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
	int T;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++) {
		cin >> n;
		vector<vector<int>> arr(2, vector<int> (n, 0));
		vector<vector<int>> dp(2, vector<int> (n, 0));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
//				cout << arr[i][j] << " ";
			}
//			cout << "\n";
		}
		int sol = 0;
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				int otherSide = j == 1 ? 0 : 1;
				dp[j][i] = dp[otherSide][i - 1] + arr[j][i];
				if (i >= 2)
					dp[j][i] = max(dp[otherSide][i - 2] + arr[j][i], dp[j][i]);
			}
		}
		sol = max(dp[0][n - 1], dp[1][n - 1]);
		cout << sol << "\n";
	}
	return (0);
}

