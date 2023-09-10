#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
using namespace std;
int n;
int sc[302];
int d[302][3];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> sc[i];
	d[1][1] = sc[1];
	d[1][2] = 0;
	d[2][1] = sc[2];
	d[2][2] = sc[1] + sc[2];
	for (int i = 3; i <= n; ++i) {
		d[i][1] = max(d[i-2][1], d[i-2][2]) + sc[i];
		d[i][2] = d[i-1][1] + sc[i];
	}
	cout << max(d[n][1], d[n][2]) << '\n';
	return (0);
}

