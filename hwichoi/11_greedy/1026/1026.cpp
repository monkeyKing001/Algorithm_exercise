#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int a[52], b[52];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	sort(a, a+n);
	sort(b, b+n);
	int s = 0;
	for (int i = 0; i < n; ++i)
		s += a[i] * b[n-i-1];
	cout << s << '\n';
	return (0);
}

