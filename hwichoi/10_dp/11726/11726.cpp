#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int d[1002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= n; ++i) d[i] = (d[i-1] + d[i-2]) % 10007;
	cout << d[n] << '\n';
	return (0);
}

