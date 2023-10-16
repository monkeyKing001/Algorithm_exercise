#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, k;
int d[102][100002];
int w[102], v[102];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			if (j < w[i]) d[i][j] = d[i-1][j];
			else d[i][j] = max(d[i-1][j], d[i-1][j-w[i]] + v[i]);
		}
	}
	cout << d[n][k] << '\n';
	return (0);
}

