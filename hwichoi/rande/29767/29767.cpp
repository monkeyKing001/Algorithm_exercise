#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, k;
long long arr[300002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	long long num = 0;
	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		num += input;
		arr[i] = num;
	}

	sort(arr, arr+n, greater<long long>());
	long long res = 0;
	for (int i = 0; i < k; ++i) {
		res += arr[i];
	}
	cout << res << '\n';
	return (0);
}

