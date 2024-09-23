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
		vector<deque<int>> dp(26);
		string w;
		int count;
		int shortest = INT_MAX;
		int longest = -1;
		cin >> w;
		cin >> count;
		for (int i = 0; i < w.size(); i++) {
			int asi = w[i] - 'a';
			dp[asi].push_back(i);
			if (dp[asi].size() == count){
				shortest = min(shortest, dp[asi].back()-dp[asi].front() + 1);
				longest = max(longest, dp[asi].back() - dp[asi].front() + 1);
				dp[asi].pop_front();
			}
		}
		if (longest != -1)
			cout << shortest << " " << longest;
		else
			cout << longest;
		cout << "\n";
	}
	return (0);
}

