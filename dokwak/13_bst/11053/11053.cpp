#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector <int> arr(n + 1);
	fill_n(arr.begin(), n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	//DP
//	vector <int> dp(n + 1);
//	fill_n(dp.begin(), n, 0);
//	for (int i = 0; i < n; i++)
//	{
//		int cur_num = arr[i];
//		for (int j = 0; j < i; j++)
//		{
//			if (arr[j] < cur_num && dp[j] + 1 > dp[i])
//				dp[i] = dp[j] + 1;
//		}
//	}
//	int sol = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (dp[i] > sol)
//			sol = dp[i];
//	}
//	cout << sol + 1;
	//BST
	vector<int> lis;
	for (int i = 0; i < n; i++)
	{
		int entry = arr[i];
		if (lis.size() == 0 || lis[lis.size() - 1] < entry)
			lis.push_back(entry);
		else
		{
			vector <int>::iterator it = lower_bound(lis.begin(), lis.end(), entry);
			*it = entry;
		}
	}
//	for (int i = 0; i < lis.size(); i++)
//	{
//		cout << lis[i] << " ";
//	}
//	cout << "\n";
	cout << lis.size();
	return (0);
}

