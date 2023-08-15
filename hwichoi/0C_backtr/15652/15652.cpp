#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n, m;
int arr[10];

void recur(int dep) {
	if (dep == m) {
		for (int i = 1; i <= m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = arr[dep]; i <= n; ++i) {
		arr[dep+1] = i;
		recur(dep+1);
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	arr[0] = 1;
	cin >> n >> m;
	recur(0);
	return (0);
}

