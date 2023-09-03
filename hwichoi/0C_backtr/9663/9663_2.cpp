#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n;
bool isused[16];
bool isused2[32];
bool isused3[32];
int cnt;

void recur(int dep) {
	if (dep == n) cnt++;
	for (int i = 0; i < n; ++i) {
		if (isused[i] || isused2[i+dep] || isused3[dep-i+n-1]) continue;
		isused[i] = 1;
		isused2[i+dep] = 1;
		isused3[dep-i+n-1] = 1;
		recur(dep+1);
		isused3[dep-i+n-1] = 0;
		isused2[i+dep] = 0;
		isused[i] = 0;
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

