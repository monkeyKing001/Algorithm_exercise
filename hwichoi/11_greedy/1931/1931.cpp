#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
pair<int, int> s[100002];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i].second >> s[i].first;
	}
	sort(s, s+n);
	int res = 0;
	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i].second < tmp) continue;
		res++;
		tmp = s[i].first;
	}
	cout << res << '\n';
	return (0);
}

