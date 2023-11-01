#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string input;
	cin >> input;
	int res = 0;
	int tmp = 0;
	bool flag = 0;
	for (int i = 0; i < input.length(); ++i) {
		if (input[i] != '+' && input[i] != '-') {
			tmp *= 10;
			tmp += input[i] - '0';
		}
		else {
			if (flag) res -= tmp;
			else res += tmp;
			tmp = 0;
			if (input[i] == '-') flag = 1;
		}
	}
	if (flag) res -= tmp;
	else res += tmp;
	cout << res << '\n';
	return (0);
}

