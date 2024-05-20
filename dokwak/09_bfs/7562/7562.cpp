#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>
#define row first;
#define col second;

using namespace std;
int dr[8] = {2, 2, -1, 1, -2, -2, -1, 1};
int dc[8] = {1, -1, -2, -2, -1, 1, 2, 2};
vector<vector<int>> board(301, vector<int> (301, -1));

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, size;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> size;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				board[i][j] = -1;
		}
		bool find = false;
		int minStepCount = 0;
		int start_r = 0, start_c = 0, target_r = 0, target_c = 0;
		cin >> start_r >> start_c >> target_r >> target_c;
		if (start_r == target_r && start_c == target_c)
			find = true;
		board[start_r][start_c] = 0;
		queue <pair <int, int> > q;
		q.push(make_pair(start_r, start_c));
		while (q.size() && !find) {
			int curR = q.front().row;
			int curC = q.front().col;
			int curStep = board[curR][curC];
			q.pop();
			int nextStep = curStep + 1;
			for (int i = 0; i < 8 && !find; i++) {
				int nextR = curR + dr[i];
				int nextC = curC + dc[i];
				if (nextR >= 0  && nextR < size && nextC >= 0 && nextC < size && board[nextR][nextC] == -1){
					board[nextR][nextC] = nextStep;
					if (nextR == target_r && nextC == target_c){
						find = true;
						minStepCount = nextStep;
						break;
					}
					q.push({nextR, nextC});
				}
			}
		}
		cout << minStepCount << "\n";
	}
	return (0);
}

