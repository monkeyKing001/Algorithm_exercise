#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, k;
int a[10001];

bool solve(int num) {
	int total = 0;
	for (int i = 0; i < k; ++i) {
		total += a[i] / num;
	}
	return total >= n;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; ++i) cin >> a[i];
	long long st = 0;
	long long en = (1l<<31)-1;
	while (st < en) {
		long long mid = (st+en+1)/2;
		if (solve(mid)) st = mid;
		else en = mid-1;
	}
	cout << st << '\n';
	return (0);
}

