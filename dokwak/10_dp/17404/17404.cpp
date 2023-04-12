#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int cost[n][3];
	for (int i = 0; i < n; i++)
	{
		int r,g,b;
		cin >> r >> g >> b;
		cost[i][0] = r;
		cost[i][1] = g;
		cost[i][2] = b;
	}
	int dp0[n][3];
	int dp1[n][3];
	int dp2[n][3];
	dp0[0][0] = cost[0][0];
	dp0[0][1] = 5000;
	dp0[0][2] = 5000;
	dp1[0][1] = cost[0][1];
	dp1[0][0] = 5000;
	dp1[0][2] = 5000;
	dp2[0][2] = cost[0][2];
	dp2[0][1] = 5000;
	dp2[0][0] = 5000;
	for (int i = 1; i < n; i++)
	{
		dp0[i][0] = min(dp0[i - 1][1], dp0[i - 1][2]) + cost[i][0];
		dp0[i][1] = min(dp0[i - 1][0], dp0[i - 1][2]) + cost[i][1];
		dp0[i][2] = min(dp0[i - 1][1], dp0[i - 1][0]) + cost[i][2];
		dp1[i][0] = min(dp1[i - 1][1], dp1[i - 1][2]) + cost[i][0];
		dp1[i][1] = min(dp1[i - 1][0], dp1[i - 1][2]) + cost[i][1];
		dp1[i][2] = min(dp1[i - 1][1], dp1[i - 1][0]) + cost[i][2];
		dp2[i][0] = min(dp2[i - 1][1], dp2[i - 1][2]) + cost[i][0];
		dp2[i][1] = min(dp2[i - 1][0], dp2[i - 1][2]) + cost[i][1];
		dp2[i][2] = min(dp2[i - 1][1], dp2[i - 1][0]) + cost[i][2];
	}
	int sol = min(dp1[n-1][0], dp2[n-1][0]);
	if (sol > min(dp0[n-1][1], dp2[n-1][1]))
		sol = min(dp0[n-1][1], dp2[n-1][1]);
	if (sol > min(dp1[n-1][2], dp0[n-1][2]))
		sol = min(dp1[n-1][2], dp0[n-1][2]);
	cout << sol;
	return (0);
}
