#include <cstring>
#include <utility>
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
int **inputMap;
int totalWallNum = 0;
int sol = 0;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

vector<pair<int, int>> virus;

void rec(int wallNum){
	if (wallNum == 3){
		//calculate
		int safeZone = (n * m) - 3 - totalWallNum;
		int **copy = new int*[n];
		bool **visited = new bool*[n];
		//memcpy(copy, inputMap, (n * m * 4));
		//memset(visited, false, n * m);
		for (int i = 0; i < n; i++) {
			copy[i] = new int[m];
			visited[i] = new bool[m];
			for (int j = 0; j < m; j++) {
				copy[i][j] = inputMap[i][j];
				visited[i][j] = false;
			}
		}
		queue<pair<int, int>> q;
		for (int i  = 0; i < virus.size(); i++){
			q.push(virus[i]);
		}
		while (!q.empty()){
			pair<int, int>cur = q.front();
			int cur_r = cur.first;
			int cur_c = cur.second;
			q.pop();
			if (visited[cur_r][cur_c])
				continue;
			visited[cur_r][cur_c] = true;
			copy[cur_r][cur_c] = 2;
			safeZone--;
			for (int i = 0; i < 4; i++) {
				int next_r = cur_r + dr[i];
				int next_c = cur_c + dc[i];
				if (next_r > -1 && next_r < n && next_c > -1 && next_c < m && 
						!visited[next_r][next_c] && copy[next_r][next_c] == 0) {
					q.push(make_pair(next_r, next_c));
				}
			}
		}
//		if (sol < safeZone){
//			cout << "found new Best sol!! : " << safeZone << "\n";
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < m; j++) {
//					cout << copy[i][j] << " ";
//				}
//				cout << "\n";
//			}
//		}
		sol = max(sol, safeZone);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inputMap[i][j] == 0){
				inputMap[i][j] = 1;
				rec(wallNum + 1);
				inputMap[i][j] = 0;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	inputMap = new int*[n];
	for (int i = 0; i < n; i++) {
		inputMap[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> inputMap[i][j];
			if (inputMap[i][j] == 2){
				virus.push_back(make_pair(i, j));
			}
			if (inputMap[i][j] == 1){
				totalWallNum++;
			}
		}
	}
	rec(0);
	cout << sol;
	return (0);
}
