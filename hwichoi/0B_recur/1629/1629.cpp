#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;
ll a, b, c;

ll recur(ll a, ll b, ll c) {
	if (b == 1) return a % c;
	ll half = recur(a, b/2, c);
	half = half * half % c;
	if (b % 2 == 0) return half;
	else return half * a % c;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c;
	cout << recur(a, b, c) << '\n';
	return (0);
}

