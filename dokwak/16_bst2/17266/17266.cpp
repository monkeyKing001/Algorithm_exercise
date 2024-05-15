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
int len;

bool possible(int h, vector<int> &pos){
	if (pos[0] - h > 0)
		return false;
	int right = pos[0] + h;
	for (int i = 1; i < pos.size(); i++) {
		if (pos[i] - h > right)
			return false;
		right = pos[i] + h;
	}
	if (right < len) 
		return false;
	return (true);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	len = n;
	vector<int> pos(m);
	for (int i = 0; i < m; i++)
		cin >> pos[i];
	int l = 1;
	int r = n + 1;
	int tempSol = r;
	while (l <= r){
		int mid = (l + r) / 2;
		if (possible(mid, pos)){
			tempSol = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << tempSol;
	return (0);
}

