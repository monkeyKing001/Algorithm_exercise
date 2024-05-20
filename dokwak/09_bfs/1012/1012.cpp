#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, n, m;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int worm = 0;
		int area = 0;
		cin >> m >> n >> area;
		queue <pair <int, int>> q;
		vector<vector<int>> map(n);
		vector<vector<bool>> visited(n);
		for (int i = 0; i < n; i++) {
			vector<int> row(m, 0);
			map[i] = row;
			vector<bool> visitedRow(m, false);
			visited[i] = visitedRow;
		}
		for (int i = 0; i < area; i++) {
			int r, c;
			cin >> c >> r;
			map[r][c] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && !visited[i][j]){
					//bfs start
					worm++;
					q.push({i, j});
					visited[i][j] = true;
					while (q.size() != 0){
						pair<int, int> cur = q.front();
						q.pop();
						int cur_r = cur.first;
						int cur_c = cur.second;
						for (int next_i = 0; next_i < 4; next_i++) {
							int next_r = cur_r + dr[next_i];
							int next_c = cur_c + dc[next_i];
							if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m){
								if (map[next_r][next_c] && !visited[next_r][next_c]){
									visited[next_r][next_c] = true;
									q.push({next_r, next_c});
								}
							}
						}
					}
				}
			}
		}
		cout << worm << "\n";
	}
	return (0);
}

