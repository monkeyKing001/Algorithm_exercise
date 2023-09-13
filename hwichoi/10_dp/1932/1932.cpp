#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
using namespace std;
int n;
int sc[502][502];
int d[502][502];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) cin >> sc[i][j];
	}
	d[1][1] = sc[1][1];
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			d[i][j] = max(d[i-1][j], d[i-1][j-1]) + sc[i][j];
		}
	}
	cout << *max_element(d[n]+1, d[n]+n+1) << '\n';
	return (0);
}

