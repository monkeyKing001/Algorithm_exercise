#include <queue>
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m;
#define MAX 100000

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++) {
		cin >> n >> m;
		int sol = -1;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
		}
		sol = n - 1;
		cout << sol << "\n";
	}
	return (0);
}

