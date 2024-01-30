#include <numeric>
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
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
	}
	int maxUse;
	cin >> maxUse;
	//make one
	sort(nums.begin(), nums.end());
	int maxNum = maxUse * nums[n - 1];
	int dp[maxNum + 1];
	memset(dp, 0, maxNum + 1);
	for (int i = 0; i < nums.size(); i++) {
		int num = nums[i];
		dp[num]++;
		for (int iter = 1; iter < maxUse; iter++) {
			dp[num + (num * iter)] = dp[num];
		}
	}
	string winner = "holsoon";
	return (0);
}

