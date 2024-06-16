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
pair<int, int> rStart;
pair<int, int> bStart;
pair<int, int> end;
int solvable = 0;
bool finished = false;

void tiltDown(){

}
void tiltUp(){

}

void tiltLeft(){

}

void tiltRight(){

}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector <vector<char>> myMap(n, vector<char>(m, 0));
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			myMap[i][j] = input[j];
			if (myMap[i][j] == '#' || myMap[i][j] == '.')
				continue;
			if (myMap[i][j] == 'R'){
				rStart = {i, j};
			}
			else if (myMap[i][j] == 'B'){
				bStart = {i, j};
			}
			else if (myMap[i][j] == 'O'){
				bStart = {i, j};
			}
		}
	}
	return (0);
}

