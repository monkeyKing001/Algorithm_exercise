#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
pair<int, int> arr[100002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		arr[i] = {a, b};
	}
	sort(arr, arr+n);
	for (int i = 0; i < n; ++i) cout << arr[i].first << ' ' << arr[i].second << '\n';
	return (0);
}

