#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int d[1001][3];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int rgb[3];
	cin >> rgb[0] >> rgb[1] >> rgb[2];
	d[0][0] = rgb[0];
	d[0][1] = rgb[1];
	d[0][2] = rgb[2];
	for (int i = 1; i < n; ++i) {
		cin >> rgb[0] >> rgb[1] >> rgb[2];
		for (int j = 0; j < 3; ++j)
			d[i][j] = min(d[i-1][(j+1)%3], d[i-1][(j+2)%3]) + rgb[j];
	}
	int ret = 0;
	ret = min({d[n-1][0], d[n-1][1], d[n-1][2]});
	cout << ret << '\n';
	return (0);
}

