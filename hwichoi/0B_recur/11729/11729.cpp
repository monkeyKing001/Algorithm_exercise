#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n;

void recur(int n, int a, int b) {
	if (n == 1) {
		cout << a << " " << b << '\n';
		return;
	}
	recur(n-1, a, 6-a-b);
	cout << a << " " << b << '\n';
	recur(n-1, 6-a-b, b);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cout << (1<<n) - 1 << '\n';
	recur(n, 1, 3);
	return (0);
}

