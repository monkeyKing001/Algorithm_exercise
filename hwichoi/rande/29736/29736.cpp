#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int a, b, k, x;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	cin >> k >> x;
	if (k+x < a || k-x > b) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	int min = k - x;
	int max = k + x;
	if (k-x < a) min = a;
	if (k+x > b) max = b;
	cout << max - min + 1 << '\n';
	return (0);
}

