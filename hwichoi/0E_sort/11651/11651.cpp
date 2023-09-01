#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
pair<int, int> arr[100002];

bool cmp(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		arr[i] = {a, b};
	}
	sort(arr, arr+n, cmp);
	for (int i = 0; i < n; ++i) cout << arr[i].first << ' ' << arr[i].second << '\n';
	return (0);
}

