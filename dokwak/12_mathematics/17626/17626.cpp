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
	cin >> n;
	int dp[50001];
	for (int i = 0; i < 50001; i++)
	{
		dp[i] = 5;
	}
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < n + 1; i++)
	{
		int temp = 1;
		int sub = temp * temp;
		while (i - sub >= 0)
		{
			if (dp[i - sub] + 1 < dp[i])
				dp[i] = dp[i - sub] + 1; 
			temp++;
			sub = temp * temp;
		}
	}
	cout << dp[n];
	return (0);
}

