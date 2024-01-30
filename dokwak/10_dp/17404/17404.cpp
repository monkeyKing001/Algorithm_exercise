#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>
#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;
int maxCost = 1100000;

void printThreeDVec(vector<vector<vector<int>>>vec){
	cout << "three Dimension vector print\n";
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			for (int k_i = 0; k_i < vec[i][j].size(); k_i++) {
				cout << vec[i][j][k_i] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n";
}

void printTwoDVec(vector<vector<int>> vec){
	cout << "two Dimension vector print\n";
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
}

void printOneDVec(vector<int> vec){
	cout << "one Dimension vector print\n";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int cost[n][3];
	for (int i = 0; i < n; i++) {
		cin >> cost[i][RED] >> cost[i][GREEN] >> cost[i][BLUE];
	}
	vector<vector<vector<int>>>dp(3);
	for (int i = 0; i < 3; i++) {
		vector<vector<int>>temp(n);
		dp[i] = temp;
		for (int j = 0; j < n; j++) {
			vector<int> ent(3, maxCost);
			dp[i][j] = ent;
		}
	}
	
	int sol = maxCost;
	dp[RED][0][RED] = cost[0][RED];
	dp[BLUE][0][BLUE] = cost[0][BLUE];
	dp[GREEN][0][GREEN] = cost[0][GREEN];
	for (int i = 1; i < n; i++) {
		dp[RED][i][RED] = min(dp[RED][i - 1][BLUE], dp[RED][i - 1][GREEN]) + cost[i][RED];
		dp[RED][i][GREEN] = min(dp[RED][i - 1][BLUE], dp[RED][i - 1][RED]) + cost[i][GREEN];
		dp[RED][i][BLUE] = min(dp[RED][i - 1][RED], dp[RED][i - 1][GREEN]) + cost[i][BLUE];
		dp[BLUE][i][BLUE] = min(dp[BLUE][i - 1][RED], dp[BLUE][i - 1][GREEN]) + cost[i][BLUE];
		dp[BLUE][i][RED] = min(dp[BLUE][i - 1][BLUE], dp[BLUE][i - 1][GREEN]) + cost[i][RED];
		dp[BLUE][i][GREEN] = min(dp[BLUE][i - 1][RED], dp[BLUE][i - 1][BLUE]) + cost[i][GREEN];
		dp[GREEN][i][GREEN] = min(dp[GREEN][i - 1][RED], dp[GREEN][i - 1][BLUE]) + cost[i][GREEN];
		dp[GREEN][i][RED] = min(dp[GREEN][i - 1][BLUE], dp[GREEN][i - 1][GREEN]) + cost[i][RED];
		dp[GREEN][i][BLUE] = min(dp[GREEN][i - 1][RED], dp[GREEN][i - 1][GREEN]) + cost[i][BLUE];
	}
	
	sol = min(dp[RED][n - 1][GREEN], sol);
	sol = min(dp[RED][n - 1][BLUE], sol);
	sol = min(dp[GREEN][n - 1][BLUE], sol);
	sol = min(dp[GREEN][n - 1][RED], sol);
	sol = min(dp[BLUE][n - 1][GREEN], sol);
	sol = min(dp[BLUE][n - 1][RED], sol);
	cout << sol;
	return (0);
}
