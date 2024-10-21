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
	long long count = 0;
	cin >> n >> m;
	vector<vector<int>> info(7, vector<int>(0));
	for (int i = 0; i < n; i++) {
		int num, flat;
		cin >> num >> flat;
		while (info[num].size() != 0 && info[num].back() > flat) {
			info[num].pop_back();
			count++;
		}
		if (info[num].size() == 0 || info[num].size() != 0 && info[num].back() != flat) {
			info[num].push_back(flat);
			count++;
		}
	}
	cout << count;
	return (0);
}

