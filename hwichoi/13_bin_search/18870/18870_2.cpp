#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n;
int a[1000002];
vector<int> sorted, uni;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sorted.push_back(a[i]);
	}
	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
	for (int i = 0; i < n; ++i) {
		cout << lower_bound(sorted.begin(), sorted.end(), a[i])-sorted.begin() << ' ';
	}
	return (0);
}

