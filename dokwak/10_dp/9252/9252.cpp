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
int dp[1001][1001];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string input1;
	string input2;
	cin >> input1;
	cin >> input2;
	input1 = "0" + input1;
	input2 = "1" + input2;
	for (int i = 0; i < input1.length(); i++)
	{
		for (int j = 0; j < input2.length(); j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (input1[i] == input2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string buf = "";
	int i = input1.length() - 1;
	int j = input2.length() - 1;
	cout << dp[i][j] << "\n";
	while (dp[i][j] != 0)
	{
		int cur_num = dp[i][j];
		if (input1[i] == input2[j])
		{
			buf = buf + input1[i];
			i--;
			j--;
		}
		else
		{
			if (dp[i - 1][j] == cur_num)
				i--;
			else if (dp[i][j - 1] == cur_num)
				j--;
		}
	}
	for (int i = 0; i < buf.length(); i++)
		cout << buf[buf.length() - 1 - i];
	return (0);
}

