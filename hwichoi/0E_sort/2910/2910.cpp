#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, c;
pair<long long, int> arr[1002];

bool cmp(pair<long long, int> &a, pair<long long, int> &b) {
	return a.second > b.second;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> c;
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		int flag = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[j].first == a) {
				arr[j].second++;
				flag = 1;
				break;
			}
		}
		if (!flag) arr[idx++] = {a, 1};
	}
	sort(arr, arr+idx, cmp);
	for (int i = 0; i < idx; ++i) {
		while (arr[i].second--) cout << arr[i].first << ' ';
	}
	return (0);
}

