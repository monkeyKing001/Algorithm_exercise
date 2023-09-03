#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int arr[2000002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n--) {
		int input;
		cin >> input;
		arr[input+1000000]++;
	}
	for (int i = 0; i < 2000002; ++i) {
		while (arr[i]--) {
			cout << i-1000000 << '\n';
		}
	}
	return (0);
}

