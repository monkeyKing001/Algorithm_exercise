#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, k;
int coin[12];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) cin >> coin[i];
	int cnt = 0;
	for (int i = n-1; i >= 0; --i) {
		int tmp = coin[i];
		if (tmp <= k) {
			cnt += k / tmp;
			k %= tmp;
		}
	}
	cout << cnt << '\n';
	return (0);
}

