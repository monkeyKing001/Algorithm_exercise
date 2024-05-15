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
int curD = 0;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int cleanedArea = 0;
int curR = -1;
int curC = -1;
bool finished = false;
vector<vector<int> > map_(50, vector<int> (50, 1));
vector<vector<int> > cleaned(50, vector<int> (50, 0));

int turnLeft(){
	curD--;
	if (curD < 0)
		curD = 3;
	return curD;
}

void clean(){
	if (!cleaned[curR][curC]){
		cleaned[curR][curC] = 1;
		cleanedArea++;
	}
}

bool moveForward(){
	curR += dr[curD];
	curC += dc[curD];
	return (true);
}

bool moveBackward(){
	int nextR = curR - dr[curD];
	int nextC = curC - dc[curD];
	if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m || map_[nextR][nextC] != 0){
		return false;
	}
	curR = nextR;
	curC = nextC;
	return true;
}

bool findUncleanedArea(){
	for (int d_i = 0; d_i < 4; d_i++) {
		turnLeft();
		int nextR = curR + dr[curD];
		int nextC = curC + dc[curD];
		if (nextR < n && nextR >= 0 && nextC < m && nextC >= 0){
			if (map_[nextR][nextC] == 0 && !cleaned[nextR][nextC]){
				return true;
			}
		}
	}
//	cout << "no cleaning area around\n";
	return (false);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> curR >> curC >> curD;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map_[i][j];
		}
	}
	while (!finished) {
//		cout << "#############         START           ############\n";
		clean();
		if (!findUncleanedArea()) {
			if (!moveBackward())
				finished = true;
		}
		else
			moveForward();
//		cout << "curR, curC end of whil() : " << curR << ", " << curC << "\n";
	}
	cout << cleanedArea;
	return (0);
}
