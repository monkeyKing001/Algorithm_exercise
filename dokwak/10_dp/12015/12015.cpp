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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int lst[1000001];
	int dp[1000001];
	fill_n(dp, 1000001, 0);
	dp[0] = 0;
	int sol = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> lst[i];
	for (int i = 1; i < n; i++)
	{
		int temp = lst[i];
		for (int j = 0; j < i; j++)
		{
			if (lst[j] < lst[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		sol = max(sol, dp[i]);
	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << dp[i] << " ";
//	}
//	cout << "\n";
	cout << sol + 1;
	return (0);
}
