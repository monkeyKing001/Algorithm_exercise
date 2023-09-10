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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; ++i) {
		d[i] = d[i-1]+1;
		if (i%3 == 0) d[i] = min(d[i], d[i/3]);
		if (i%2 == 0) d[i] = min(d[i], d[i/2]);
	}
	cout << d[n] << '\n';
	return (0);
}

