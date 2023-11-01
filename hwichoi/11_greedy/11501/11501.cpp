#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int t, n;
int input[1000002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		long long res = 0;
		for (int i = 0; i < n; ++i) cin >> input[i];
		int max = input[n-1];
		for (int i = n-2; i >= 0; --i) {
			if (input[i] > max) max = input[i];
			else res += max - input[i];
		}
		cout << res << '\n';
	}
	return (0);
}

