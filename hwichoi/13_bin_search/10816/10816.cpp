#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int a[500001];

int lower_idx(int target, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st+en)/2;
		if (a[mid] >= target) en = mid;
		else st = mid+1;
	}
	return st;
}

int upper_idx(int target, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st+en)/2;
		if (a[mid] > target) en = mid;
		else st = mid+1;
	}
	return st;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a+n);
	cin >> m;
	while (m--) {
		int input;
		cin >> input;
		cout << upper_idx(input, n)-lower_idx(input, n) << '\n';
	}
	return (0);
}

