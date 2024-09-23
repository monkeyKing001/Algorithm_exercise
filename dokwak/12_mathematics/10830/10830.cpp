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
int mod = 1000;

const vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b){
	vector<vector<int>> temp(n, vector<int>(n, 0));
	for (int r_i = 0; r_i < n; r_i++) {
		for (int c_i = 0; c_i < n; c_i++) {
			int next_num = 0;
			for (int cc_i = 0; cc_i < n; cc_i++) {
				next_num += ((a[r_i][cc_i] % mod) * (b[cc_i][c_i] % mod)) % mod;
				next_num %= mod;
			}
			temp[r_i][c_i] = next_num;
		}
	}
	return (temp);
}

//const vector<vector<int>> pow(vector<vector<int>> &a, vector<vector<int>> &record){
void pow(vector<vector<int>> &a, vector<vector<int>> &record){
	vector<vector<int>> temp(n, vector<int>(n, 0));
	for (int r_i = 0; r_i < n; r_i++) {
		for (int c_i = 0; c_i < n; c_i++) {
			int next_num = 0;
			for (int cc_i = 0; cc_i < n; cc_i++) {
				next_num += ((a[r_i][cc_i] % mod) * (a[cc_i][c_i] % mod)) % mod;
				next_num %= mod;
			}
			record[r_i][c_i] = next_num;
		}
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	long long b;
	cin >> b;
	vector<vector<int>> arr(n, vector<int>(n ,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<int>> curArr(arr);
	long long curPow = b;
	vector<long long> prime_pow;
	while (curPow != 0){
		long long tempNum = (long long)1;
		while (tempNum * (long long)2 <= curPow)
			tempNum *= (long long)2;
		prime_pow.push_back(tempNum);
		curPow -= tempNum;
	}
	int maxLayer = (int)log2((double)prime_pow.front()) + 1;
//	cout << "maxLayer : " << maxLayer << "\n";
	vector<vector<vector<int>>> dp(maxLayer, vector<vector<int>> (n, (vector<int> (n, 0))));
	dp[0] = arr;
	for (int i = 1; i < maxLayer; i++) {
		pow(dp[i - 1], dp[i]);
	}
	vector<vector<int>> e(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) 
		e[i][i] = 1;
	curArr = e;
	for (int i = 0; i < prime_pow.size(); i++) {
		long long pow = prime_pow[i];
		int layer = (int)log2((double)pow);
		curArr = multiply(curArr, dp[layer]);
	}
	//print
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << curArr[i][j] << " ";
		}
		cout << "\n";
	}
	return (0);
}

