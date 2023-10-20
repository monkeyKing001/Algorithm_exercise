#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int arr[1002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr+n);
	int tmp = 0;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		tmp += arr[i];
		res += tmp;
	}
	cout << res << '\n';
	return (0);
}

