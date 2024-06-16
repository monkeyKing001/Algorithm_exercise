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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> buildings(n, 0);
	for (int i = 0; i < n; i++) 
		cin >> buildings[i];
	vector<vector<double>> tan(n, vector<double> (n, 0));
	for (int i = 0; i < n; i++) {
		int curH = buildings[i];
		for (int j = i + 1; j < n; j++) {
			int nextH = buildings[j];
			tan[i][j] = (double)(nextH - curH) / (double)abs(j - i);
			tan[j][i] = -tan[i][j];
		}
	}
	vector<int> count (n, 0);
	int sol = -1;
	for (int i = 0; i < n; i++) {
		int cur = i;
//		cout << "cur : " << cur << "\n";
		//leftCount

		double leftMax = INT_MIN;
		for (int j = cur - 1; j >= 0; j--) {
			if (tan[cur][j] > leftMax){
				count[cur]++;
				leftMax = tan[cur][j];
			}
		}
		//right count
		double rightMax = INT_MIN;
		for (int j = cur + 1; j < n; j++) {
			if (tan[cur][j] > rightMax){
				count[cur]++;
				rightMax = tan[cur][j];
			}
		}
//		cout << "count of cur : " << count[cur] << "\n";
		sol = max(sol, count[cur]);
	}
	cout <<sol;
	return (0);
}

