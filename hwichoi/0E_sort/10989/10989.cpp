#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int arr[10002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		arr[a]++;
	}
	for (int i = 0; i < 10001; ++i) {
		while (arr[i]--) cout << i << '\n';
	}
	return (0);
}

