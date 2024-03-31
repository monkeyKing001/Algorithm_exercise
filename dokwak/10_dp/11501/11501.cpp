#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 0;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++) {
		int day = 0;
		cin >> day;
		stack<ll> s;
		ll profit = 0;
		ll dp[day];
		ll info[day];
		for (int i = 0; i < day; i++)
			cin >> info[i];
		for (int i = day - 1; i >= 0; i--){
			dp[i] = info[i];
			if (i != day - 1){
				dp[i] = max(dp[i], dp[i + 1]);
			}
		}
		for (int i = 0; i < day; i++) {
			profit += dp[i] - info[i];
		}
		cout << profit << "\n";
	}
	return (0);
}

