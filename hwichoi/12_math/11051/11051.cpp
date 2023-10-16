#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, k;
int d[1002][1002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		d[i][0] = 1;
		d[i][i] = 1;
		for (int j = 1; j < i; ++j)
			d[i][j] = (d[i-1][j] + d[i-1][j-1]) % 10007;
	}
	cout << d[n][k] << '\n';
	return (0);
}

