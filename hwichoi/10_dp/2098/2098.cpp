#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

#define INF 100000000;
using namespace std;
int n;
int w[18][18];
int d[18][(1<<16)+2];

int tsp(int tmp, int visited) {
	if (visited == (1<<n)-1) {
		if (w[tmp][0] == 0) return INF;
		return w[tmp][0];
	}

	if (d[tmp][visited] != -1) return d[tmp][visited];
	d[tmp][visited] = INF;

	for (int i = 1; i < n; ++i) {
		if (!w[tmp][i]) continue;
		if (visited & 1<<i) continue;
		d[tmp][visited] = min(d[tmp][visited], w[tmp][i] + tsp(i, visited+(1<<i)));
	}
	return d[tmp][visited];
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		fill(d[i], d[i] + (1<<n), -1);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> w[i][j];
	cout << tsp(0, 1) << '\n';
	return (0);
}

