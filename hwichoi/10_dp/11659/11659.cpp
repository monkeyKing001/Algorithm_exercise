#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int d[100002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> d[1];
	for (int i = 2; i <= n; ++i) {
		int input;
		cin >> input;
		d[i] = d[i-1] + input;
	}
	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << d[j]-d[i-1] << '\n';
	}
	return (0);
}

