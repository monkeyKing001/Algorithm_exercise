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
int d[302];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int total = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> sc[i];
		total += sc[i];
	}
	d[1] = sc[1];
	d[2] = sc[2];
	d[3] = sc[3];
	for (int i = 4; i <= n; ++i) {
		d[i] = min(d[i-2], d[i-3]) + sc[i];
	}
	cout << total-min(d[n-1], d[n-2]) << '\n';
	return (0);
}

