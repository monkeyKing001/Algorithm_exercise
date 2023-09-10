#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int tc, n, m;
int arr1[20002], arr2[20002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) cin >> arr1[i];
		for (int i = 0; i < m; ++i) cin >> arr2[i];
		sort(arr1, arr1+n);
		sort(arr2, arr2+m);
		int total = 0;
		int j = m - 1;
		for (int i = n-1; i >= 0; --i) {
			while (j >= 0 && arr1[i] <= arr2[j]) j--;
			total += j+1;
		}
		cout << total << '\n';
	}
	return (0);
}

