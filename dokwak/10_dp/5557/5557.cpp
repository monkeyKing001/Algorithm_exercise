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
	long long sol = 0;
	vector<vector<long long>> dp_2d(110, vector<long long> (30, 0));
	int first;
	cin >> first;
	dp_2d[0][first] = 1;
	for (int i = 1; i < n - 1; i++) {
		int number;
		cin >> number;
		for (int plus_i = 0; plus_i + number < 21; plus_i++) {
			int next_number = plus_i + number;
			dp_2d[i][next_number] += dp_2d[i- 1][plus_i];
		}
		for (int minus_i = 0; minus_i < 21; minus_i++) {
			if (minus_i - number < 0)
				continue;
			int next_number = minus_i - number;
			dp_2d[i][next_number] += dp_2d[i - 1][minus_i];
		}
	}
	int last_num;
	cin >> last_num;
	sol = dp_2d[n - 2][last_num];
//	for (int i = 1; i < 21; i++) {
//		cout << i << "\t";
//	}
//	cout << "\n\n";
//	for (int i = 0; i < n; i++) {
//		for (int j = 1; j < 21; j++) {
//			cout << dp_2d[i][j] << "\t";
//		}
//		cout << "\n";
//	}
	cout << sol;
	return (0);
}

