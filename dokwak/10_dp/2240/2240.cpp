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
	int T, W;
	cin >> T >> W;
	int sol = 0;
	vector<vector<vector<int>>> dp(T, vector<vector<int>>(W + 1, vector<int>(3, 0)));
	for (int t_i = 0; t_i < T; t_i++) {
		int tree_num;
		cin >> tree_num;
		int other_tree_num = tree_num == 1 ? 2 : 1;
		if (t_i == 0){
			//not move
			if (tree_num == 1)
				dp[t_i][W][tree_num] = 1;
			//move
			else
				dp[t_i][W - 1][tree_num] = 1;
		}
		else {
			//hit
			for (int w_i = W; w_i >= W - t_i - 1 && w_i >= 0; w_i--) {
//				if (w_i == W && tree_num == 2)
//					continue;
				//lower bound
				if (w_i != W - t_i - 1)
					dp[t_i][w_i][tree_num] = dp[t_i - 1][w_i][tree_num] + 1;
				//upper bound
				if (w_i != W)
					dp[t_i][w_i][tree_num] = max(dp[t_i][w_i][tree_num], dp[t_i - 1][w_i + 1][other_tree_num] + 1);
			}
			//miss
			for (int w_i = W; w_i >= W - t_i - 1 && w_i >= 0; w_i--) {
				//miss with staying vs miss with moving
				dp[t_i][w_i][other_tree_num] = dp[t_i - 1][w_i][other_tree_num];
				if (w_i !=  W)
					dp[t_i][w_i][other_tree_num] = max(dp[t_i - 1][w_i][other_tree_num], dp[t_i - 1][w_i + 1][tree_num]);
			}
		}
//		cout << "t_i : " << t_i << "\n";
//		for (int w_i = 0; w_i < W + 1; w_i++) {
//			cout << w_i << "\t";
//			cout << dp[t_i][w_i][1] << ", " <<dp[t_i][w_i][2]<< "\n";
//		}
	}
	for (int i = 0; i < W + 1; i++) {
//		cout << dp[T - 1][i][1] << ", " <<dp[T - 1][i][2]<< "\n";
		sol = max(sol, dp[T - 1][i][1]);
		sol = max(sol, dp[T - 1][i][2]);
	}
	cout << sol;
	return (0);
}

