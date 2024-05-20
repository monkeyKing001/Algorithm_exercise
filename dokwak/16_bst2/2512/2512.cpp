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
int sol = 0;

bool possible(vector<int> &req, int k){
	int budget = m;
	for (int i = 0; i < req.size(); i++) {
		if (req[i] <= k)
			budget -= req[i];
		else
			budget -= k;
		if (budget < 0)
			return false;
	}
	return (true);
}
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> req(n , 0);
	for (int i = 0; i < n; i++) {
		cin >> req[i];
	}
	sort(req.begin(), req.end());
	cin >> m;
	int l = m / n;
	int r = req.back();
	sol = l;
	while (l <= r){
		int mid = (l + r) / 2;
		if (possible(req, mid)){
			l = mid + 1;
			sol = mid;
		}
		else 
			r = mid - 1;
	}
	cout << sol;
	return (0);
}
