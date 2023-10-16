#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int d[100002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	d[1] = 1;
	int sq = 2;
	for (int i = 2; i <= n; ++i) {
		if (i == sq*sq) {
			d[i] = 1;
			sq++;
		}
		else if (d[i]) d[i] = min(d[i-1]+1, d[i]);
		else d[i] = d[i-1]+1;
		for (int j = 2; j*j <= i; ++j) {
			int k = j*j;
			if (i+k > 100000) break;
			if (d[i+k]) d[i+k] = min(d[i+k], d[i]+1);
			else d[i+k] = d[i]+1;
		}
	}
	cout << d[n] << '\n';
	return (0);
}

