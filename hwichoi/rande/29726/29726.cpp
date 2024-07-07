#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[200002];
int mindp[200002], maxdp[200002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	mindp[0] = 100001;
	for (int i = 1; i <= m+1; ++i) {
		mindp[i] = min(arr[i], mindp[i-1]);
		maxdp[n+1-i] = max(arr[n+1-i], maxdp[n+2-i]);
	}
	int res = -100001;
	for (int i = 1; i <= m+1; ++i) {
		int tmp = maxdp[n-m-1+i] - mindp[i];
		res = max(res, tmp);
	}
	cout << res;
}

