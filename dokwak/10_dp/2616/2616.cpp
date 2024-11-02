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

void printOneDVec(vector<int> vec){
	cout << "one Dimension vector print\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> dp(1, 0);
	vector<int> info(1, 0);
	cin >> n;
	info.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> info[i];
	}
	cin >> m;
	int sol = 0;
	for (int car_i = 0; car_i < 3; car_i++) {
		int temp_max_sum = 0;
		int temp_max_idx = -1;
		dp.resize(info.size(), 0);
		for (int i = 0; i < info.size(); i++) {
			dp[i] = info[i];
			if (i > 0)
				dp[i] += dp[i - 1];
		}
		for (int i = 0; i + m  - 1 <= info.size() - 1 ; i++) {
			int sum = dp[i + m - 1] - dp[i] + info[i];
			if (sum > temp_max_sum){
				temp_max_sum = sum;
				temp_max_idx = i;
			}
		}
//		cout << "\nidx, sum : " << temp_max_idx << ", " <<temp_max_sum;
		info.erase(info.begin() + temp_max_idx, info.begin() + temp_max_idx + m);
//		printOneDVec(info);
		sol += temp_max_sum;
	}
	cout << sol;
	return (0);
}
