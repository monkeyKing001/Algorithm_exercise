#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int t, n, m, x, y;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> m >> n >> x >> y;
		int mx = lcm(m, n);
		int flag = 1;
		if (y == n) y = 0;
		for (int i = x; i <= mx; i += m) {
			if (i % n == y) {
				cout << i << '\n';
				flag = 0;
				break;
			}
		}
		if (flag) cout << -1 << '\n';
	}
	return (0);
}

