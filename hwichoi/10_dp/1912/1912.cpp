#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int arr[100002];
int d[100002];

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
		d[i] = max(d[i], d[i-1] + arr[i]);
	}
	cout << *max_element(d+1, d+n+1) << '\n';
	return (0);
}

