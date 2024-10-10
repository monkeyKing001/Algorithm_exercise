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
vector<int> info;
vector<int> dp(100001, INT_MAX);

int bst(int key){
	int idx = -1;
	int l = 0;
	int r = info.size() - 1;
	while (l <= r){
		int mid = (l + r) / 2;
		if (info[mid] > key){
			r = mid - 1;
		}
		else{
			idx = mid;
			l = mid + 1;
		}
	}
	return (idx);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 1; i < 100001; i++) {
		int pw = i * i;
		if (pw >= 100001)
			break;
		dp[pw] = 1;
		info.push_back(pw);
	}
	for (int i = 1; i < 100001; i++) {
		int cur_num = i;
		if (dp[cur_num] == 1)
			continue;
		int max_pw_idx = bst(cur_num);
		for (int j = max_pw_idx; j >= 0; j--) {
			int max_pw = info[j];
			int minus_num = cur_num - max_pw;
			dp[cur_num] = min(dp[cur_num], dp[max_pw] + dp[minus_num]);
		}
	}
	cout << dp[n];
//	cout << dp[82009] << "\n";
//	cout << dp[89005] << "\n";
//	cout << dp[61495] << "\n";
//	cout << dp[2542] << "\n";
//	cout << dp[77882] << "\n";
//	cout << dp[10198] << "\n";
//	cout << dp[37961] << "\n";
//	cout << dp[98952] << "\n";
//	cout << dp[35057] << "\n";
	return (0);
}

