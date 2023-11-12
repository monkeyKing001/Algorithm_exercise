#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, k;
bool era[1001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 2; i <= n; ++i) {
		if (era[i]) continue;
		for (int j = 1; j*i <= n; ++j) {
			if (!era[j*i]) {
				era[j*i] = 1;
				k--;
				if (!k) {
					cout << j*i << '\n';
					return 0;
				}
			}
		}
	}
	return (0);
}

