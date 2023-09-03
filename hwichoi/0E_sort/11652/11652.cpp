#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
long long arr[100002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr+n);
	long long maxval = -(1ll << 62);
	int cnt = 0;
	int maxcnt = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0 || arr[i] == arr[i-1]) {
			cnt++;
			continue;
		}
		if (cnt > maxcnt) {
			maxcnt = cnt;
			maxval = arr[i-1];
		}
		cnt = 1;
	}
	if (cnt > maxcnt) maxval = arr[n-1];
	cout << maxval << '\n';
	return (0);
}

