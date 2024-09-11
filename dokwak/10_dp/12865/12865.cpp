#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int max_weight = 100001;
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> weight_dp(n, vector<int> (k + 1, 0));
	vector<pair<int, int>> info_weight;
	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		info_weight.push_back({w, v});
	}
	sort(info_weight.begin(), info_weight.end());
	//solve with weight dp
	for (int i = 0; i < info_weight.size(); i++) {
		int cur_w = info_weight[i].first;
		int cur_value = info_weight[i].second;
		if (i == 0){
			weight_dp[i][cur_w] = cur_value;
		}
		else{
			for (int j = 0; j < cur_w; j++) {
				weight_dp[i][j] = weight_dp[i - 1][j];
			}
			for (int j = cur_w; j < k + 1; j++) {
				weight_dp[i][j] = max(weight_dp[i - 1][j], weight_dp[i - 1][j - cur_w] + cur_value);
			}
		}
	}
	int sol = INT_MIN;
	for (int i = 0; i < k + 1; i++) {
		sol = max(sol, weight_dp[n - 1][i]);
	}
	cout << sol << "\n";
	return (0);
}
