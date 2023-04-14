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
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	int dp[s1.length() + 1][s2.length() + 1];
	for (int i = 0; i < s1.length() + 1; i++)
	{
		for (int j = 0; j < s2.length() + 1; j++)
			dp[i][j] = 0;
	}
	for (int i = 0; i < s1.length() ; i++)
	{
		for (int j = 0; j < s2.length(); j++)
		{
			if (s1[i] == s2[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else 
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);  
		}
	}
	cout << dp[s1.length()][s2.length()];
	return (0);
}
