#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	string s;
	cin >> s;
	char c = s[n-1];
	string mo = "yuiophjklbnm";
	for (char a : mo) {
		if (a == c) {
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << 1 << '\n';
	return (0);
}

