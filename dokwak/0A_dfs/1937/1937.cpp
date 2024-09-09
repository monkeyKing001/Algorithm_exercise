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
int sol = -1;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};
vector<vector<int>> g(500, vector<int> (500, 0));
vector<vector<int>> dp(500, vector<int> (500, 0));

int dfs(int curR, int curC){
	for (int i = 0; i < 4; i++) {
	}
	int ret = 0;
	return (ret);
}
//void dfs(int curR, int curC, vector<vector<int>> &visited){
////	cout << "now r, c : " << curR << ", " << curC << "\n";
//	int curCount = dp[curR][curC];
//	for (int i = 0; i < 4; i++) {
//		int nextR = curR + dr[i];
//		int nextC = curC + dc[i];
//		if (nextR < n && nextR >= 0 \
//				&& nextC < n && nextC >= 0 && \
//				g[nextR][nextC] > g[curR][curC]){
//			if (visited[nextR][nextC] == 0){
//				//if traveled
//				if (dp[nextR][nextC] != -1){
//					dp[curR][curC] = max(dp[curR][curC], curCount + dp[nextR][nextC]);
////					cout << "traveled already r, c, count: " << nextR << ", " 
////						<< nextC << ", "<< dp[nextR][nextC] << "\n";
//				}
//				//else if not traveled,
//				else if (dp[nextR][nextC] == -1){
//					visited[nextR][nextC] = 1;
//					dp[nextR][nextC] = 1;
////					cout << "trave new r, c, count: " << nextR << ", " 
////						<< nextC << ", "<< dp[nextR][nextC] << "\n";
//					dfs(nextR, nextC, visited);
//					dp[curR][curC] = max(dp[curR][curC], curCount + dp[nextR][nextC]);
//					visited[nextR][nextC] = 0;
//				}
//			}
//			//if visited already, pass
//		}
//		sol = max(sol, dp[curR][curC]);
//	}
//}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == -1){//no traveled
				cout << "start r, c : " << i << ", " << j << "\n";
				dp[i][j] = dfs(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sol = max(sol, dp[i][j]);
		}
	}
	cout << sol;
	return (0);
}

