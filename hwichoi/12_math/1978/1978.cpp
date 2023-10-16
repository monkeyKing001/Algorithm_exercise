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
	int res = 0;
	while (n--) {
		int tmp;
		cin >> tmp;
		if (tmp == 1) continue;
		int flag = 0;
		for (int j = 2; j*j <= tmp; ++j) {
			if (tmp % j == 0) {
				flag = 1;
				break;
			}
		}
		if (!flag) res++;
	}
	cout << res << '\n';
	return (0);
}

