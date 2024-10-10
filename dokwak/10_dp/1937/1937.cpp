#include <random>
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

int dr[4] = {0, 1, -1, 0};
int dc[4] = {1, 0, 0, -1};

vector<vector<int>> map_(501, vector<int>(501, 0));
vector<vector<int>> dp(501, vector<int>(501, -1));

vector<pair<int, int>> find_next_position(int cur_r, int cur_c){
	vector<pair<int, int>> ret;
	for (int i = 0; i < 4; i++) {
		int next_r = cur_r + dr[i];
		int next_c = cur_c + dc[i];
		if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n) {
			if (map_[next_r][next_c] > map_[cur_r][cur_c]) {
				ret.push_back({next_r, next_c});
			}
		}
	}
	return (ret);
}

int dfs(int cur_r, int cur_c){
	int &maximum_count = dp[cur_r][cur_c];
	if (maximum_count != -1){
		return dp[cur_r][cur_c];
	}
	maximum_count = 1;
	vector<pair<int, int>> next_pos = find_next_position(cur_r, cur_c);
	for (int i = 0; i < next_pos.size(); i++) {
		pair <int, int> next_position = next_pos[i];
		maximum_count = max(maximum_count, dfs(next_position.first, next_position.second) + 1);
	}
	return (maximum_count);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map_[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (find_next_position(i, j).size() != 0){
				q.push({i, j});
			}
		}
	}
	int sol = 1;
	while (q.size() != 0){
		pair<int, int> point = q.front();
		q.pop();
		sol = max(sol, dfs(point.first, point.second));
	}
	cout << sol;
	return (0);
}

