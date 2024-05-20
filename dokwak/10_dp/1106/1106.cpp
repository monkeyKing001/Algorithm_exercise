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
int minCustomer = 0;
int maxCost = 100001;
#define getCustomer first
#define costToPromo second

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> info;
	cin >> minCustomer >> n;
	int limit = (minCustomer + 101);
	vector<int> dp(limit, maxCost);
	for (int i = 0; i < n; i++) {
		int cost, customer;
		cin >> cost >> customer;
		info.push_back({customer, cost});
	}
	sort(info.begin(), info.end());
	for (int i = 0; i < info.size(); i++) {
		int customer = info[i].getCustomer;
		int cost = info[i].costToPromo;
		dp[customer] = min(dp[customer], cost);
	}
	int sol = 100001;
	for (int i = 0; i < limit; i++) {
		for (int j = 0; j <= i - j; j++) {
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
			if (i >= minCustomer)
				sol = min(sol, dp[i]);
		}
	}
	cout << sol;
	return (0);
}
