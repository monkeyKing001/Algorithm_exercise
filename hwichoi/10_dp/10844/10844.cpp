#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
long long d[102][10];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i < 10; ++i) d[1][i] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j == 0) {
				d[i][j] = d[i-1][1]; continue;
			}
			if (j == 9) {
				d[i][j] = d[i-1][8]; continue;
			}
			d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % 1000000000;
		}
	}
	int ret = 0;
	for (int i : d[n]) ret = (ret + i) % 1000000000;
	cout << ret << '\n';
	return (0);
}

