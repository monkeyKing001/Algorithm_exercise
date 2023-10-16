#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int rope[100002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> rope[i];
	sort(rope, rope+n);
	int mx = 0;
	for (int i = 1; i <= n; ++i)
		mx = max(mx, rope[n-i] * i);
	cout << mx << '\n';
	return (0);
}

