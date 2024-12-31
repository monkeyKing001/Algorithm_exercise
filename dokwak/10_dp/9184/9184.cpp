#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<vector<int>>> dp(21, vector<vector<int>> (21, vector<int>(21, 0)));

int fun(int a, int b, int c){
	if (a <= 0 || b <= 0 || c <= 0)
		return (1);
	if (a > 20 || b > 20 || c > 20)
		return (dp[20][20][20]);
	return (dp[a][b][c]);
}
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int a_i = 0; a_i < 21; a_i++) {
		for (int b_i = 0; b_i < 21; b_i++) {
			for (int c_i = 0; c_i < 21; c_i++) {
				if (a_i == 0 || b_i == 0 || c_i == 0)
					dp[a_i][b_i][c_i] = 1;
				else if (a_i < b_i && b_i < c_i)
					dp[a_i][b_i][c_i] = dp[a_i][b_i][c_i - 1] + dp[a_i][b_i - 1][c_i - 1] - dp[a_i][b_i - 1][c_i];
				else
					dp[a_i][b_i][c_i] =
							dp[a_i - 1][b_i][c_i] + \
							dp[a_i - 1][b_i - 1][c_i] + \
							dp[a_i - 1][b_i][c_i - 1] - \
							dp[a_i - 1][b_i - 1][c_i - 1];
			}
		}
	}
	int a, b, c;
	cin >> a >> b >> c;
	while (a != -1 || b != -1 || c != -1){
		cout << "w(" << a << ", " << b << ", " << c << ") = " << fun(a, b, c) << "\n";
		cin >> a >> b >> c;
	}
	
	return (0);
}

