#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, q;
int arr[200001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr+n);
	for (int i = 0; i < q; ++i) {
		int input;
		cin >> input;
		if (!binary_search(arr, arr+n, input)) {
			cout << 0 << '\n';
			continue;
		}
		int tmp = upper_bound(arr, arr+n, input)-arr;
		int left = tmp-1;
		int right = n-tmp;
		cout << left * right << '\n';
	}
	return (0);
}

