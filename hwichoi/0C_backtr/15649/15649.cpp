#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[10];
bool isused[10] = {};
int n, m;

void recur(int dep) {
	if (dep == m) {
		for (int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (isused[i]) continue;
		isused[i] = 1;
		arr[dep] = i;
		recur(dep+1);
		isused[i] = 0;
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	recur(0);
	return (0);
}

