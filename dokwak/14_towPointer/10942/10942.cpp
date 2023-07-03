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
int dp[2001][2001];
int arr[2001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
//	for (int i = 0; i < n; i++)
//	{
//		cout << arr[i] << "\t";
//	}
//	cout << "\n";
	//inf loop. why?
	for (int i = 0; i < n; i++)
	{
//		cout << "i : " << i << "\n";
		for (int j = i; j >= 0; j--)
		{
//			cout << "j : " << j << "\n";
			if (i == j)
				dp[j][i] = 1;
			else if (arr[i] == arr[j])
			{
				if (i - j == 1 && dp[j][i - 1] == 1)
					dp[j][i] = 1;
				else if (i - j == 1 && dp[j][i - 1] != 1)
					dp[j][i] = 0;
				else if (i - j != 1 && dp[j + 1][i - 1] == 1)
					dp[j][i] = 1;
			}
			else {
				dp[j][i] = 0;
			}
		}
	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << dp[i][j] << "\t";
//		}
//		cout << "\n";
//	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s - 1][e - 1] << "\n";
	}
	return (0);
}
