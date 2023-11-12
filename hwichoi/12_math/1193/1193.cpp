#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i < 10000; ++i) {
		if (n <= i) {
			if (i % 2 == 0) cout << n << "/" << i-n+1 << '\n';
			else cout << i-n+1 << "/" << n << '\n';
			return 0;
		}
		else n -= i;
	}
	return (0);
}

