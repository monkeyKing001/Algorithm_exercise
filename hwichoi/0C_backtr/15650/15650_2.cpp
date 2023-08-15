#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
int n, m;
int arr[10];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		if (i > m-1) arr[i] = 1;
		else arr[i] = 0;
	}
	do {
		for (int i = 0; i < n; ++i)
			if (arr[i] == 0) cout << i+1 << ' ';
		cout << '\n';
	} while (next_permutation(arr, arr+n));
	return (0);
}

