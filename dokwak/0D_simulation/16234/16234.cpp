#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, l, r;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, -1, 0, 1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> r;
	int map[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int stage = 0;
	vector<vector<pair<int, int>>> group;
	while (true){
		group.clear();
		bool visited[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				visited[i][j] = false;
			}
		}
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]){
					//group aling start;
					int start_r = i;
					int start_c = j;
					vector<pair<int, int>> sameGroup;
					q.push(make_pair(start_r, start_c));
					group.push_back(sameGroup);
//					std::cout << "start r, c " << i <<", " << j<<std::endl;
					//bfs
					while (!q.empty()){
						pair<int, int> cur = q.front();
						q.pop();
						int cur_r = cur.first;
						int cur_c = cur.second;
						if (visited[cur_r][cur_c])
							continue;
						visited[cur_r][cur_c] = true;
						group.back().push_back(cur);
						for (int d_i = 0; d_i < 4; d_i++) {
							int next_r = cur_r + dr[d_i];
							int next_c = cur_c + dc[d_i];
							if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n && !visited[next_r][next_c]){
								if (abs(map[cur_r][cur_c] - map[next_r][next_c]) >= l && abs(map[cur_r][cur_c] - map[next_r][next_c]) <= r) {
									q.push({next_r, next_c});
								}
							}
						}
					}
				}
			}
		}
		if (group.size() == n * n)
			break;
		//moving
		for (int i = 0; i < group.size(); i++) {
			int sum = 0;
			vector<pair<int, int>> sameGroup = group[i];
			if (sameGroup.size() == 1)
				continue;
			//get new population num
			for (int j = 0; j < sameGroup.size(); j++) {
				int cur_r = sameGroup[j].first;
				int cur_c = sameGroup[j].second;
				sum += map[cur_r][cur_c];
			}
			for (int j = 0; j < sameGroup.size(); j++) {
				int cur_r = sameGroup[j].first;
				int cur_c = sameGroup[j].second;
				map[cur_r][cur_c] = sum / sameGroup.size();
			}
		}
		stage++;
	}
	cout << stage;
	return (0);
}
