#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int n, m;
int idx[10];
int arr[10];
int isused[10];

void recur(int dep) {
	if (dep == m) {
		for (int i = 0; i < m; ++i) cout << arr[i] << ' ';
		return ;
	}
	for (int i = dep+1; i <= n; ++i) {
		

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> idx[i];
	sort(idx, idx+n);
	return (0);
}

