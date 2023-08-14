#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n, s;
int arr[22];
int cnt, cur;

void recur(int dep) {
	if (dep == n) {
		if (cur == s) cnt++;
		return;
	}
	cur += arr[dep];
	recur(dep+1);
	cur -= arr[dep];
	recur(dep+1);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	recur(0);
	if (s == 0) cnt--;
	cout << cnt << '\n';
	return (0);
}

