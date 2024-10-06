#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
double min_tan = -1110000000;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> buildings(n, 0);
	for (int i = 0; i < n; i++) 
		cin >> buildings[i];
	vector<vector<double>> info(n, vector<double> (n, 0));
	for (int i = 0; i < n; i++) {
		int cur_building = i;
		int cur_h = buildings[i];
		for (int j = i + 1; j < n; j++) {
			int w = (j - i);
			int next_h = buildings[j];
			double tan = (double)(next_h - cur_h) / (double)w;
			info[i][j] = tan;
			info[j][i] = -tan;
		}
	}
	int sol = 0;
	for (int i = 0; i < n; i++) {
		//left view count;
		int count = 0;
//		cout << "cur building, h : " << i << ", " << buildings[i] << "\n";
		double left_max = min_tan;
		for (int j = i - 1; j >= 0; j--) {
			if (info[i][j] > left_max){
				count++;
				left_max = info[i][j];
			}
		}
		//right view count;
		double right_max = min_tan;
		for (int j = i + 1; j < n; j++) {
			if (info[i][j] > right_max){
				count++;
				right_max = info[i][j];
			}
		}
		sol = max(sol, count);
	}
	cout << sol;
	return (0);
}

