#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n, r, c;
int cnt = 0;

int recur(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1<<(n-1);
	int ret = r / half * 2 + c / half;
	return ret * half * half + recur(n-1, r%half, c%half);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> r >> c;
	cout << recur(n, r, c) << '\n';
	return (0);
}

