#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
string a, b;
int d[1002][1002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	for (int i = 1; i <= a.length(); ++i) {
		for (int j = 1; j <= b.length(); ++j) {
			if (a[i-1] == b[j-1]) d[i][j] = d[i-1][j-1] + 1;
			else d[i][j] = max(d[i-1][j], d[i][j-1]);
		}
	}
	cout << d[a.length()][b.length()] << '\n';
	return (0);
}

