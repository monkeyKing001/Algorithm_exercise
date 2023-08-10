#include <bits/stdc++.h>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	int i;
	cin >> i;
	int input;
	while (i--) {
		cin >> input;
		v.push_back(input);
	}
	cin >> input;
	int ret = 0;
	for (int i : v) {
		if (i == input)
			ret++;
	}
	cout << ret << endl;
	return (0);
}

