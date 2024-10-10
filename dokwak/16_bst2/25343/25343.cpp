#include <type_traits>
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
int dr[2] = {0, 1};
int dc[2] = {1, 0};
int sol = 1;


void printOneDVec(vector<int> vec){
	cout << "one Dimension vector print\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

int find_smallest_bigger(const vector<int> &arr, int key){
	int idx = -1;
	int l = 0;
	int r = arr.size() - 1;
	while (l <= r){
		int mid = (l + r) / 2;
		if (key <= arr[mid]){
			idx = mid;
			r = mid - 1;
		}
		else 
			l = mid + 1;
	}
	return (idx);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<vector<int>> info(n, vector<int> (n, 0));
	vector<vector<int>> dp(n, vector<int> (n, 0));
	vector<vector<vector<int>>> dp_3d(n, vector<vector<int>> (n, vector<int>(0)));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> info[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vector<vector<int>> temp;
			for (int d_i = 0; d_i < 2; d_i++) {
				int prev_r = i - dr[d_i];
				int prev_c = j - dc[d_i];
				if (prev_r >= 0 && prev_c >= 0){
					temp.push_back(dp_3d[prev_r][prev_c]);
				}
			}
		}
	}
	cout << sol;
	return (0);
}

