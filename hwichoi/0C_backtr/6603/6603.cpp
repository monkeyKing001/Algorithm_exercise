#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int input[15];
int idx[15];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n) {
		for (int i = 0; i < n; ++i) {
			cin >> input[i];
			if (i < 6) idx[i] = 0;
			else idx[i] = 1;
		}
		sort(input, input+n);
		do {
			for (int i = 0; i < n; ++i)
				if (idx[i] == 0) cout << input[i] << ' ';
			cout << '\n';
		} while (next_permutation(idx, idx+n));
		cout << '\n';
		cin >> n;
	}
	return (0);
}

