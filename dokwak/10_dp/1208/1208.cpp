#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int s;
	ll count;
	cin >> n >> s;
	vector<int> arr(n, 0);
	vector<int> left_nums(n / 2, 0);
	vector<int> right_nums(n - (n / 2), 0);
	map<int, int> left_sums;
	for (int i = 0; i < n; i++){
		if (i < n / 2){
			cin >> left_nums[i];
		}
		else if (i >= n / 2){
			cin >> right_nums[i - (n / 2)];
		}
	}
	for (int bits = 0; bits < (1 << left_nums.size()); bits++) {
		int temp_sum = 0;
		for (int i = 0; i < left_nums.size(); i++){
			if (bits & (1 << i))
				temp_sum += left_nums[i];
		}
		left_sums[temp_sum]++;
	}
	for (int bits = 0; bits < (1 << right_nums.size()); bits++) {
		int temp_sum = 0;
		for (int i = 0; i < right_nums.size(); i++){
			if (bits & (1 << i))
				temp_sum += right_nums[i];
		}
//		cout << temp_sum << "\n";
		int target_num = s - temp_sum;
		count += left_sums[target_num];
	}
	if (s == 0)//exclude s = 0 and choose nothing left, right
		count--;
	cout << count;
	return (0);
}

