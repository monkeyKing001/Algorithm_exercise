#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int a[500001], b[500001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	sort(a, a+n);
	sort(b, b+m);
	vector<int> res;
	for (int i = 0; i < n; ++i)
		if (!binary_search(b, b+m, a[i])) res.push_back(a[i]);
	if (res.empty()) cout << "0\n";
	else {
		cout << res.size() << '\n';
		for (int i : res) cout << i << ' ';
	}
	return (0);
}

