#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int arr[10];
int input[10];
int idx[10];

void recur(int dep) {
	if (dep == m) {
		for (int i = 0; i < m; ++i) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = idx[dep]; i < n; ++i) {
		if (tmp == input[i]) continue;
		arr[dep] = input[i];
		tmp = input[i];
		idx[dep+1] = i;
		recur(dep+1);
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> input[i];
	sort(input, input+n);
	recur(0);
	return (0);
}

