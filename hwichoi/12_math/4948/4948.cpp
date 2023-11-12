#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
bool era[260000];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i*i <= 2*123456; ++i) {
		if (era[i]) continue;
		for (int j = 2; j*i <= 2*123456; ++j)
			era[i*j] = 1;
	}
	while (1) {
		cin >> n;
		if (!n) return 0;
		int cnt = 0;
		for (int i = n+1; i <= 2*n; ++i) {
			if (!era[i]) cnt++;
		}
		cout << cnt << '\n';
	}
	return (0);
}

