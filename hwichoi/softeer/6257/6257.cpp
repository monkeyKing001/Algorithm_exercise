#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int arr[5001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	long long cnt = 0;
	for (int i = 0; i < n-2; ++i) {
		long long tmp = 0;
		for (int j = n-1; j > i; --j) {
			if (arr[i] > arr[j]) tmp++;
			else if (arr[i] < arr[j]) cnt += tmp;
		}
	}
	cout << cnt << '\n';
	return (0);
}

