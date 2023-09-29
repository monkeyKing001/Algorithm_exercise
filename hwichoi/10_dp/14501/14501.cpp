#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int d[20];
int t[20], p[20];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> t[i] >> p[i];
	d[1] = 0;
	for (int i = 2; i <= n+1; ++i) {
		int mx = 0;
		for (int j = 1; j < i; ++j) {
			if (i-j < t[j]) continue;
			mx = max(mx, d[j] + p[j]);
		}
		d[i] = mx;
	}
	cout << d[n+1] << '\n';
	return (0);
}

