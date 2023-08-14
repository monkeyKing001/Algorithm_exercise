#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n, m;
int arr[10];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		arr[i] = i+1;
	do {
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		reverse(arr+m, arr+n);
	} while (next_permutation(arr, arr+n));
	return (0);
}

