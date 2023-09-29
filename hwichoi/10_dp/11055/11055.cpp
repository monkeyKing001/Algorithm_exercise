#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int arr[1002], d[1002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		d[i] = arr[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j)
			if (arr[j] < arr[i]) d[i] = max(d[i], d[j] + arr[i]);
	}
	cout << *max_element(d+1, d+n+1) << '\n';
	return (0);
}

