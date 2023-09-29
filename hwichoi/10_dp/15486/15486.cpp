#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int d[1500005];
int t[1500005], p[1500005];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> t[i] >> p[i];
	for (int i = 1; i <= n+1; ++i) {
		d[i] = max(d[i], d[i-1]);
		if (i+t[i] <= n+1)
			d[i+t[i]] = max(d[i+t[i]], d[i] + p[i]);
	}
	cout << d[n+1] << '\n';
	return (0);
}
