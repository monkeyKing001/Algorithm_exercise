#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int t, n, m;
int coin[21];
int d[10002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> coin[i];
		cin >> m;
		fill(d, d+m+1, 0);
		d[0] = 1;
		for (int i = n-1; i >= 0; --i)
			for (int j = coin[i]; j <= m; ++j)
				d[j] += d[j-coin[i]];
		cout << d[m] << '\n';
	}
	return (0);
}

