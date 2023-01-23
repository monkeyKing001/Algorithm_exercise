#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return (b);
	return (gcd(b % a, a));
}

int lcm(int a, int b)
{
	return (a / gcd(a, b) * b);
}

int ans(int m, int n, int x, int y)
{
	if(x == m) x = 0;
	if(y == n) y = 0;
	int l = lcm(m, n);
	for (int i = x; i <= l; i += m) {
		if (i == 0) continue;
		if (i % n == y)
			return i;
	}
	return -1;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n , m, test_num, x, y;
	cin >> test_num;
	for (int i = 0; i < test_num; ++i) {
		cin >> m >> n >> x >> y;
		cout << ans(m , n, x, y) << "\n";
	}
	return (0);
}

