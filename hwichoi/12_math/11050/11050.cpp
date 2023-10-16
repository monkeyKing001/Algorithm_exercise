#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, k;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	int ret = 1;
	for (int i = 1; i <= n; ++i) ret *= i;
	for (int i = 1; i <= k; ++i) ret /= i;
	for (int i = 1; i <= n-k; ++i) ret /= i;
	cout << ret;
	return (0);
}

