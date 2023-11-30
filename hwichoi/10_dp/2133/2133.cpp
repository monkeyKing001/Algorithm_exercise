#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int dp[31][2];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	dp[2][0] = 3;
	dp[2][1] = 0;
	dp[4][0] = dp[2][0]*3;
	dp[4][1] = 2;
	for (int i = 6; i <= n; i += 2) {
		dp[i][0] = (dp[i-2][0] + dp[i-2][1]) * 3;
		dp[i][1] = dp[i-2][1] + (dp[i-4][0]+dp[i-4][1])*2;
	}
	cout << dp[n][0]+dp[n][1] << '\n';
	return (0);
}

