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
	cin >> n >> m;
	vector<pair<int, int>> info(n);
	for (int i = 0; i < n; i++) {
		int h, price;
		cin >> h >> price;
		info[i] = {h, price};
	}
	int curH = 0, curC = 0;
	sort(info.begin(), info.end());
	return (0);
}

