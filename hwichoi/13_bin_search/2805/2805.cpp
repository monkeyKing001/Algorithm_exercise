#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int arr[1000001];

bool solve(int num) {
	long long total = 0;
	for (int i = 0; i < n; ++i) {
		if (num > arr[i]) continue;
		total += arr[i] - num;
	}
	return (total >= m);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	int st = 0;
	int en = 100000000;
	int mid;
	while (st < en) {
		mid = (st + en + 1) / 2;
		if (solve(mid)) st = mid;
		else en = mid-1;
	}
	cout << st << '\n';
	return (0);
}

