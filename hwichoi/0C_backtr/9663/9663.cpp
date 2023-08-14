#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n;
int arr[16];
int cnt;

void recur(int dep) {
	if (dep == n) cnt++;
	for (int i = 0; i < n; ++i) {
		int flag = 0;
		for (int j = 0; j < dep; ++j) {
			if (arr[j] == i || abs(dep-j) == abs(i-arr[j])) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			arr[dep] = i;
			recur(dep+1);
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	recur(0);
	cout << cnt << '\n';
	return (0);
}

