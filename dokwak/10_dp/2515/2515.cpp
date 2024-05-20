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
	cin >> n >> m;
	int minHeightDiff = m;
	vector<pair<int, int>> info(n);
	for (int i = 0; i < n; i++) {
		int h, price;
		cin >> h >> price;
		info[i] = {h, price};
	}
	sort(info.begin(), info.end());
	vector<int> heightDp(n, -1);
	int curLimit = -1;
	for (int i = 1; i < n; i++) {
		int height = info[i].first;
		while (curLimit + 1 < n && height - info[curLimit + 1].first >= minHeightDiff)
			curLimit++;
		heightDp[i] = curLimit;
	}
//	for (int i = 0; i < n; i++) {
//		int height = info[i].first;
//		cout << height << " ";
//	}
//	cout << "\n";
//	for (int i = 0; i < n; i++) {
//		int height = info[i].first;
//		cout << heightDp[i] << " ";
//	}
//	cout << "\n";
	vector<int> dp(n, 0);
	dp[0] = info[0].second;
	for (int i = 1; i < n; i++) {
		int maximumIdx = heightDp[i];
		int curH = info[i].first;
		int curPrice = info[i].second;
		if (maximumIdx != - 1){
			dp[i] = max(dp[maximumIdx] + curPrice, dp[i - 1]);
		}
		else 
			dp[i] = max(dp[i - 1], curPrice);
	}
	cout << dp[n - 1];
	return (0);
}
