#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int a[1000002];

bool solve(int num) {
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		cnt += a[i] / num;
	}
	return cnt >= n;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) cin >> a[i];
	long long st = 0;
	long long en = 1000000000;
	while (st < en) {
		int mid = (st+en+1)/2;
		if (solve(mid)) st = mid;
		else en = mid-1;
	}
	cout << st << '\n';
	return (0);
}

