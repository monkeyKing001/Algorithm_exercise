#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int a[500001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a+n);
	cin >> m;
	while (m--) {
		int input;
		cin >> input;
		cout << binary_search(a, a+n, input) << '\n';
	}
	return (0);
}

