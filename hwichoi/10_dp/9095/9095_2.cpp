#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int tc, n;
int arr[13];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> tc;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i < 11; ++i) {
		arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
	}
	while (tc--) {
		cin >> n;
		cout << arr[n] << '\n';
	}
	return (0);
}

