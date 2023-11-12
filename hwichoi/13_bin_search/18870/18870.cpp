#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int a[1000002], sorted[1000002], to_search[1000002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sorted[i] = a[i];
	}
	sort(sorted, sorted+n);
	int cnt = 0;
	int prev = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0 || sorted[i] != prev) to_search[cnt++] = sorted[i];
		prev = sorted[i];
	}
	for (int i = 0; i < n; ++i) {
		cout << lower_bound(to_search, to_search+cnt, a[i]) - to_search << ' ';
	}
	return (0);
}

