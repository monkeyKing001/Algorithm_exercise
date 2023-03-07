#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
int max_w;
int dp[101][100001];
bool comp(pair <int, int> a, pair<int, int> b)
{
	return (a.first < b.first);
}
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector <pair <int, int> > load;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		load.push_back(make_pair(w, v));
	}
	for (int i = 1; i <= k; i++)
	{
		int item_w = load[0].first;
		int item_v = load[0].second;
		if (item_w <= i)
			dp[0][i] = item_v;
	}
	for (int i = 1; i < n; i++)
	{
		int item_w = load[i].first;
		int item_v = load[i].second;
		for (int j = 1; j <= k; j++)
		{
			int max_w = j;
			//max(not choose, choose)
			if (max_w - item_w >= 0)
			{
				dp[i][j] = max(dp[i - 1][max_w],
						dp[i - 1][max_w - item_w] + item_v);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
//	for (int i = 0; i < n; i++)
//	{
//		int item_w = load[i].first;
//		int item_v = load[i].second;
//		for (int j = 1; j <= k; j++)
//		{
//			int max_w = j;
//			//max(not choose, choose)
//			cout << dp[i][j] << " ";
//		}
//		cout << "\n";
//	}
	cout << dp[n-1][k] << "\n";
//	sort(load.begin(), load.end(), comp);
	//wrong way
//	for (int i = 1; i <= k; i++)
//	{
//		for (int j = 1; j <= i / 2; j++)
//		{
//			if (j != i - j 
//					&&
//					dp[i - j]
//					&&
//					dp[j]
//					&&
//					dp[i] < dp[j] + dp[i - j])
//			{
////				cout
////					<< "dp["
////					<< i
////					<< "] : "
////					<< dp[i]
////					<< " =  dp["
////					<< j
////					<< "] : "
////					<< dp[j]
////					<< " dp["
////					<< i - j
////					<< "] : "
////					<< dp[i - j] << "\n";
//				dp[i] = dp[j] + dp[i - j];
//			}
//		}
//	}
	return (0);
}
