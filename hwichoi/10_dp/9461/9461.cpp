#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n,t;
long long d[102];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;
	d[5] = 2;
	for (int i = 6; i <= 100; ++i) d[i] = d[i-1] + d[i-5];
	while (t--) {
		cin >> n;
		cout << d[n] << '\n';
	}
	return (0);
}

