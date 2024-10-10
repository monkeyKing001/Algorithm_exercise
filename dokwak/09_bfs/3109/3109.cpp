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
int sol = 0;
int dr[3] = {-1, 0, 1};
int dc[3] = {1, 1, 1};

vector<vector<int>> map_;
vector<vector<bool>> visited;

void printTwoDVec(vector<vector<int>> vec){
	cout << "two Dimension vector print\n";
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
}
bool dfs(int cur_r, int cur_c){
	map_[cur_r][cur_c] = 1;
	if (cur_c == m - 1)
		return true;
	for (int d_i = 0; d_i < 3; d_i++) {
		int next_r = cur_r + dr[d_i];
		int next_c = cur_c + dc[d_i];
		if (next_r >= 0 && next_r < n && map_[next_r][next_c] == 0){
			if (dfs(next_r, next_c))
				return true;
		}
	}
	return false;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<char, int> map_char = {{'.', 0},{'x', 1}};
	cin >> n >> m;
	map_.resize(n, vector<int> (m, 0));
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			map_[i][j] = map_char[str[j]];
		}
	}
	for (int i = 0; i < n; i++) {
		int start_r = i;
		int start_c = 0;
		if (dfs(start_r, start_c))
			sol++;
	}
	cout << sol;
	return (0);
}

