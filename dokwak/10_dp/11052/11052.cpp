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
	vector<int> cost(n + 1);
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> cost[i + 1];
		dp[i + 1] = cost[i + 1];
	}
	dp[1] = cost[1];
	for (int i = 1; i < n + 1; i++) {
		int num = i;
		int cur = num;
		while (cur <= n){
			dp[cur] = max(dp[cur], dp[cur - num] + dp[num]);
			cur += num;
		}
	}
	for (int i = 2; i < n + 1; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[n];
	return (0);
}

