#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
char arr[26][26];
bool vis[26][26];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
char dd[4] = {'>', '^', '<', 'v'};
string min_string = "";
string tmp_string;
pair<int, int> min_start;
int min_cnt;

bool is_fin() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == '#' && vis[i][j] == 0)
				return 0;
		}
	}
	return 1;
}

void func(int x, int y, int dir, pair<int, int> start, int dep) {
	if (dep == min_cnt) {
		if (is_fin() && (min_string.empty() || min_string.length() > tmp_string.length())) {
			min_string = tmp_string;
			min_start = start;
		}
		return;
	}
	int nx = x + dx[dir] * 2;
	int ny = y + dy[dir] * 2;
	if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] == 1 || arr[nx][ny] == '.') {
		/*
		if (tmp_string.length() >= min_cnt && is_fin() && (min_string.empty() || min_string.length() > tmp_string.length())) {
			min_string = tmp_string;
			min_start = start;
		} */
		return;
	}
	vis[nx][ny] = 1;
	vis[nx-dx[dir]][ny-dy[dir]] = 1;
	tmp_string.push_back('A');

	func(nx, ny, dir, start, dep+1);
	tmp_string.push_back('L');
	func(nx, ny, (dir+1)%4, start, dep+1);
	tmp_string.pop_back();
	tmp_string.push_back('R');
	func(nx, ny, (dir+3)%4, start, dep+1);
	tmp_string.pop_back();

	tmp_string.pop_back();
	vis[nx][ny] = 0;
	vis[nx-dx[dir]][ny-dy[dir]] = 0;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int sharp_cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == '#') sharp_cnt++;
		}
	min_cnt = sharp_cnt/2;
	int idx = 0;
	tmp_string = "";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == '.') continue;
			for (int dir = 0; dir < 4; ++dir) {
				for (int i = 0; i < n; ++i)
					fill(vis[i], vis[i]+m, 0);
				vis[i][j] = 1;
				tmp_string.push_back(dd[dir]);
				func(i, j, dir, {i+1, j+1}, 0);
				tmp_string.pop_back();
			}
		}
	}
	cout << min_start.first << ' '<< min_start.second << '\n';
	for (int i = 0; i < min_string.length(); ++i) {
		cout << min_string[i];
		if (i == 0) cout << '\n';
	}
	cout << '\n';
	return (0);
}

