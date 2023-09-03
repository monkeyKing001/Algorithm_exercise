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
int idx[10];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr+n);
	for (int i = 0; i < n; ++i) {
		if (i < m) idx[i] = 0;
		else idx[i] = 1;
	}
	do {
		for (int i = 0; i < n; ++i)
			if (!idx[i]) cout << arr[i] << ' ';
		cout << '\n';
	} while (next_permutation(idx, idx+n));
	return (0);
}

