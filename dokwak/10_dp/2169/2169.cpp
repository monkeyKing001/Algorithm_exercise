#include <bits/stdc++.h>

using namespace std;
using info = pair<int, int>;
int n, m;
int min_cost = -110000000;
int dr[3] = {1, 0, 0};
int dc[3] = {0, -1, 1};
vector<vector<int>> map_;
vector<vector<info>> path_;
vector<vector<vector<int>>> dp;
vector<vector<bool>> visited_;
int rec(int r, int c, int dir){
	if (r == n - 1 && c == m - 1)
		return(map_[n - 1][m - 1]);
	if (dp[r][c][dir] != min_cost)
		return dp[r][c][dir];
	for (int i = 0; i < 3; i++) {
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m && !visited_[next_r][next_c]){
			visited_[next_r][next_c] = true;
			dp[r][c][dir] = max(dp[r][c][dir], rec(next_r, next_c, i) + map_[r][c]);
			visited_[next_r][next_c] = false;
		}
	}
	return (dp[r][c][dir]);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	map_.resize(n, vector<int> (m, 0));
	dp.resize(n, vector<vector<int>> (m, vector<int>(3, min_cost)));
	visited_.resize(n, vector<bool> (m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map_[i][j];
		}
	}
	visited_[0][0] = true;
	int sol = rec(0, 0, 0);
	cout << sol;
	return (0);
}

