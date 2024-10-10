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
vector<vector<int>> map_;
int dr[4] = {0, 1, -1, 0};
int dc[4] = {1, 0, 0, -1};

void printTwoDVec(vector<vector<int>> &vec){
	cout << "two Dimension vector print\n";
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
}

int count_ocean_face(int r, int c){
	int face_count = 0;
	for (int i = 0; i < 4; i++) {
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m && map_[next_r][next_c] == 0)
			face_count++;
	}
	return (face_count);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	map_.resize(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map_[i][j];
		}
	}
	bool finish = false;
	int stage = 0;
	queue<pair<int, int>> q;
	int continent_count;
	while (!finish) {
		continent_count = 0;
		vector<vector<int>> next_stage_info;
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map_[i][j] != 0 && !visited[i][j]) {
					continent_count++;
					q.push({i, j});
					visited[i][j] = true;
					while (q.size() != 0){
						int cur_r = q.front().first;
						int cur_c = q.front().second;
						q.pop();
						int face_count = count_ocean_face(cur_r,cur_c);
						next_stage_info.push_back({cur_r, cur_c, face_count});
						for (int d_i = 0; d_i < 4; d_i++) {
							int next_r = cur_r + dr[d_i];
							int next_c = cur_c + dc[d_i];
							if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m){
								if (map_[next_r][next_c] != 0 && !visited[next_r][next_c]){
									visited[next_r][next_c] = true;
									q.push({next_r, next_c});
								}
							}
						}
					}
				}
			}
		}
		//if continent splited, finish
		if (continent_count != 1){
			finish = true;
			break;
		}
		//else update staget and map
		stage++;
		//update map
		for (int i = 0; i < next_stage_info.size(); i++) {
			int r = next_stage_info[i][0];
			int c = next_stage_info[i][1];
			int face_count = next_stage_info[i][2];
			map_[r][c] = max(0, map_[r][c] - face_count);
		}
//		cout << "stage : " << stage << "\n";
//		printTwoDVec(map_);
	}
	//finish with no iceberg
	if (continent_count == 0)
		stage = 0;
	cout << stage;
	return (0);
}

