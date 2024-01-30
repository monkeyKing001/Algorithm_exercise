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
int dr[] = {0, 0, 0, 1, -1};
int dc[] = {0, 1, -1, 0, 0};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector <pair<int, int>> point;
	int curR = 0, curC = 0;
	point.push_back({curR, curC});
	int mostLeft = 0, mostRight = 0, mostUp = 0, mostDown = 0;
	cin.ignore();
	string buf;
	getline(cin, buf);
	while (buf.length() != 0){
		stringstream ss(buf);
		int dir, len;
		ss >> dir >> len;
		curR += len * dr[dir];
		curC += len * dc[dir];
		mostLeft = min(curC, mostLeft);
		mostUp = min(curR, mostUp);
		mostRight = max(curC, mostRight);
		mostDown = max(curR, mostDown);
		point.push_back({curR, curC});
		getline(cin, buf);
	}
	int innerR, innerC;
	int outerR, outerC;
	for (int i = 0; i < point.size(); i++) {
//		cout << "r, c : " << point[i].first << ", "<< point[i].second << "\n";
		int r = point[i].first;
		int c = point[i].second;
		if (r != mostUp && r != mostDown && c != mostLeft && c != mostRight){
			innerR = r;
			innerC = c;
		}
		if ((r == mostUp || r == mostDown) && (c != mostLeft && c != mostRight)){
			outerR = r;
		}
		if ((r != mostUp && r != mostDown) && (c == mostLeft || c == mostRight)){
			outerC = c;
		}
	}
//	cout << "inner R, C : " << innerR << ", " << innerC << "\n";
//	cout << "outer R, C : " << outerR << ", " <<outerC << "\n";
	int totalOrigin = abs(mostLeft - mostRight) * abs(mostUp - mostDown);
	int del = abs(innerR - outerR) * abs(innerC - outerC);
//	cout << "totalOrigin : " << totalOrigin << "\n";
//	cout << "del : " << del << "\n";
	int sol = (totalOrigin - del) * n;
	cout << sol << "\n";
	return (0);
}

