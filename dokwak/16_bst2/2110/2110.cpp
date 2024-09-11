#include <queue>
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
int total_c;
int max_distance = -1;
int sol = INT_MIN;
int max_of_min_distance = -1;

bool possible(const vector<int> &info, int try_minimum_distance) {
	int min_distance = INT_MAX;
	int rest_c = total_c - 1;
	int last_house = info.front();
	for (int i = 1; i < info.size() && rest_c > 0; i++) {
		int cur = info[i];
		if (cur - last_house >= try_minimum_distance) {
			min_distance = min(min_distance, cur - last_house);
			last_house = cur;
			rest_c--;
		}
	}
	if (rest_c > 0)
		return false;
	max_of_min_distance = max(max_of_min_distance, min_distance);
	return true;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	total_c = m;
	vector<int> pos(n, -1);
	for (int i = 0; i < n; i++) 
		cin >> pos[i];
	sort(pos.begin(), pos.end());
	max_distance = pos.back() - pos.front();
	int l = 0;
	int r = max_distance;
	while (l <= r){
		int mid = (l + r) / 2;
		if (possible(pos, mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	sol = max_of_min_distance;
	cout << sol;
	return (0);
}
