#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
long long arr[1000002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		string str = to_string(arr[i]);
		reverse(str.begin(), str.end());
		arr[i] = stoll(str);
	}
	sort(arr, arr+n);
	for (int i = 0; i < n; ++i) cout << arr[i] << '\n';
	return (0);
}

