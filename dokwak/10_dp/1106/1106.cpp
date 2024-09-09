#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>
#define COST first
#define CUSTOMER second
using namespace std;
int n, m;
int max_cost = 100001;
int sol = max_cost;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> info;
	vector<int> dp(1111, max_cost);//min cost for customer
	int customer, city_count;
	dp[0] = 0;
	cin >> customer >> city_count;
	for (int i = 0; i < city_count; i++) {
		int cost, return_customer;
		cin >> cost >> return_customer;
		info.push_back({return_customer, cost});
	}
	sort(info.begin(), info.end());
	for (int i = 0; i < info.size(); i++) {
		int return_customer = info[i].first;
		int cur_cost = info[i].second;
		for (int j = return_customer; j < customer + 101; j++) {
			dp[j] = min(dp[j], cur_cost + dp[j - return_customer]);
		}
	}
	for (int i = customer; i < customer + 101; i++) {
		sol = min(sol, dp[i]);
	}
	cout << sol;
	return (0);
}
