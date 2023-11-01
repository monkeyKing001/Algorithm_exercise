#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
pair<pair<int, int>, pair<int, int>> t[100002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		t[i] = {{a, b}, {c, d}};
	}
	sort(t, t+n);
	int cnt = 1;
	pair<int, int> start = {3, 1};
	pair<int, int> max = {0, 0};
	int i = 0;
	if (t[i].first > start) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (t[i].first > start) {
			if (t[i].first > max) break;
			start = max;
			cnt++;
		}
		if (t[i].second > max) max = t[i].second;
		if (max.first == 12) break;
	}
	if (max.first != 12) {
		cout << "0\n";
		return 0;
	}
	cout << cnt << '\n';
	return 0;
}

