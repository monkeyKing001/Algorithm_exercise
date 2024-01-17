#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m, r, c, k;
int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0};
deque<int> side;
deque<int> front;
int curR = 0;
int curC = 0;
int **diceMap;
void move(int cmd){
	if (cmd == 1){
		int pop = side[3]; side.pop_back();
		side.push_front(pop);
		front[1] = side[1];
		front[3] = side[3];
	}
	else if (cmd == 2){
		int pop = side[0]; side.pop_front();
		side.push_back(pop);
		front[1] = side[1];
		front[3] = side[3];
	}
	else if (cmd == 3){
		int pop = front[3]; front.pop_back();
		front.push_front(pop);
		side[1] = front[1];
		side[3] = front[3];
	}
	else if (cmd == 4){
		int pop = front[0]; front.pop_front();
		front.push_back(pop);
		side[1] = front[1];
		side[3] = front[3];
	}
	if (diceMap[curR][curC] == 0){
		diceMap[curR][curC] = side[3];
	}
	else{
		side[3] = diceMap[curR][curC];
		front[3] = diceMap[curR][curC];
		diceMap[curR][curC] = 0;
	}
	cout << front[1] << "\n";
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> r >> c >> k;
	diceMap = new int*[n];
	for (int i = 0; i < n; i++) {
		diceMap[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> diceMap[i][j];
		}
	}
	curR = r;
	curC = c;
	for (int i = 0; i < 4; i++) {
		side.push_back(0);
		front.push_back(0);
	}
	for (int i = 0; i < k; i++) {
		int cmd = 0;
		cin >> cmd;
		int nextR = curR + dr[cmd];
		int nextC = curC + dc[cmd];
		//movable
		if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m){
//			cout << "move : " << cmd << "\n";
			curR = nextR;
			curC = nextC;
//			cout << "cur R, C : " << curR << ", "<< curC <<"\n";
			move(cmd);
		}
	}
	return (0);
}

