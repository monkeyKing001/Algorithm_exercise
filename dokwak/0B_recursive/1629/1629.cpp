#include <bits/stdc++.h>
using ll =  long long;
using namespace std;
// get (a^b) % b
// be catuion for int overflow and time complexity
ll mod(ll a, ll b, ll m)
{
	ll a_n, b_n;
	ll ret = 0;
	if (b == 1)
		return (a % m);
	b_n = b / 2;
	a_n = mod(a, b_n, m);
	ret = a_n * a_n % m;
	if (b % 2 == 0)
		return (ret);
	else
		return (ret * a % m);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	a, b, c;
	cin >> a >> b >> c;
	cout << mod(a, b, c);
	return (0);
}
