#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int l, p, v;
	int i = 1;
	while (true) {
		cin >> l >> p >> v;
		if (!l && !p && !v) return 0;
		int res = v/p * l + min(v%p, l);
		cout << "Case " << i++ << ": " << res << '\n';
	}
	return (0);
}

