#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int t, n;
int d[41][2];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	d[0][0] = 1; d[0][1] = 0;
	d[1][0] = 0; d[1][1] = 1;
	for (int i = 2; i <= 40; ++i) {
		d[i][0] = d[i-1][0] + d[i-2][0];
		d[i][1] = d[i-1][1] + d[i-2][1];
	}
	while (t--) {
		cin >> n;
		cout << d[n][0] << ' ' << d[n][1] << '\n';
	}
	return (0);
}

