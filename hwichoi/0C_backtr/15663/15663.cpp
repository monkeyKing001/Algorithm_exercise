#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int input[10];
bool isused[10];
int arr[10];
int pre[10];

void recur(int dep) {
	if (dep == m) {
		for (int i = 0; i < m; ++i) {
			cout << arr[i] << ' ';
			pre[i] = arr[i];
		}
		cout << '\n';
	}
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		if (isused[i] || tmp == input[i]) continue;
		isused[i] = 1;
		arr[dep] = input[i];
		tmp = input[i];
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
	for (int i = 0; i < n; ++i) cin >> input[i];
	sort(input, input+n);
	recur(0);
	return (0);
}

