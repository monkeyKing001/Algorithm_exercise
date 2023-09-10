#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int d[1000002];
int rd[1000002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	d[1] = 0;
	rd[1] = 0;
	for (int i = 2; i <= n; ++i) {
		int midx = i-1;
		d[i] = d[i-1]+1;
		if (i%3 == 0) {
			d[i] = min(d[i/3]+1, d[i]);
			if (d[i/3] < d[i]) midx = i/3;
		}
		if (i%2 == 0) {
			d[i] = min(d[i/2]+1, d[i]);
			if (d[i/2] < d[i]) midx = i/2;
		}
		rd[i] = midx;
	}
	cout << d[n] << '\n';
	int k = n;
	while (k != 0) {
		cout << k << ' ';
		k = rd[k];
	}
	cout << '\n';
	return (0);
}

