#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int arr[1001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	long long msg = n-1;
	for (int i = 0; i < m; ++i) {
		int input;
		cin >> input;
		arr[i] = input;
		if (i == 0) {
			cout << n-1 << '\n';
			continue;
		}
		msg += n-1;
		for (int j = i-1; j >= 0; --j) {
			if (arr[j] == input) {
				msg -= i - j - 1;
				break;
			}
			if (j == 0) {
				msg -= i;
			}
		}
		cout << msg << '\n';
	}
	return (0);
}

