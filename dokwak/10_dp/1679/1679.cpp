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
int *dp;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	int maxUse;
	cin >> maxUse;
	int maxNumber = (nums.back() * maxUse);
	dp = new int[maxNumber + 1];
	fill_n(dp, maxNumber + 1, 0);

	//make single number combination.
	for (int i = 0; i < nums.size(); i++) {
		int number = nums[i];
		int curNum = number; //1st bug
		int max = number * maxUse;
		int prev = 0;
		while (curNum <= max){
			dp[curNum] = dp[prev] + 1;
			prev = curNum;
			curNum += number;
		}
	}
	for (int i = 1; i < maxNumber + 1; i++) {
		if (dp[i] == 0){//couldn't make number
			dp[i] = maxUse + 1; //second bug dp[i] is zero
			int l = 1, r = i - 1;
//			cout << "couldn't make : " << i << "\n";
			while (l <= r){
//				cout << "l, r : " << l << ", " << r << "\n";
				dp[i] = min(dp[l] + dp[r], dp[i]);
				l++;
				r--;
			}
		}
	}
//	for (int i = 1; i < maxNumber + 1; i++) {
//		cout << dp[i] << " ";
//	}
//	cout << "\n";
	string winner = "holsoon";
	int notMade = -1;
	for (int i = 1; i < maxNumber + 1; i++) {
		if (dp[i] == 0 || dp[i] > maxUse){
			winner = (i % 2 == 0) ? "holsoon" : "jjaksoon";
			notMade = i;
			break;
		}
	}
	cout << winner <<" win at " << notMade;
	return (0);
}

