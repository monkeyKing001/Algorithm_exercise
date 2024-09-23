#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

#define H first
#define C second

using namespace std;
int n, m;
vector<pair<int, int>> info;
vector <int> dp;

int bst(int i){
	int cur_h = info[i].H;
	int cur_c = info[i].C;
	int l = 0, r = i;
	int biggest_smaller = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (cur_h - info[mid].H >= m){
			biggest_smaller = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return (biggest_smaller);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int minHeightDiff = m;
	info.resize(n, {0, 0});
	dp.resize(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int h, c;
		cin >> h >> c;
		info[i].H = h;
		info[i].C = c;
	}
	sort(info.begin(), info.end());
	int sol = -1;
	dp[0] = info[0].C;
	for (int i = 1; i < n; i++) {
		int cur_h = info[i].H;
		int cur_c = info[i].C;
		int biggest_smaller_index = bst(i);
		if (biggest_smaller_index != -1)
			dp[i] = max(dp[i - 1], dp[biggest_smaller_index] + cur_c);
		else
			dp[i] = max(dp[i - 1], cur_c);
//		cout << "cur_h, cur_c, dp[i + 1] = "
//			<< cur_h
//			<< ", "
//			<< cur_c
//			<< ", "
//			<< dp[i + 1]
//			<< "\n";
	}
	sol =  dp[n - 1];
	cout << sol;
	return (0);
}
