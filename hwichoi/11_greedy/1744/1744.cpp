#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int arr[51];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr+n, greater<int>());
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] <= 0) break;
		if (i < n-1 && arr[i] > 1 && arr[i+1] > 1){
			res += arr[i]*arr[i+1];
			i++;
		}
		else res += arr[i];
	}
	for (int i = n-1; i >= 0; --i) {
		if (arr[i] > 0) break;
		if (i-1 > 0 && arr[i] < 0 && arr[i-1] <= 0) {
			res += arr[i]*arr[i-1];
			i--;
		}
		else res += arr[i];
	}
	cout << res << '\n';
	return (0);
}

