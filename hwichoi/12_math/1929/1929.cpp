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
	cin >> n >> m;
	vector<bool> state(m+1, true);
	for (int i = 2; i*i <= m; ++i) {
		if (!state[i]) continue;
		for (int j = i*i; j <= m; j += i)
			state[j] = false;
	}
	for (int i = n; i <= m; ++i) {
		if (state[i]) cout << i << '\n';
	}
	return (0);
}

