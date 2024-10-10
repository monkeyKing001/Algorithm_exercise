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
vector<int> position(220, -1);
int find_smallest_bigger_idx(vector<int> &arr, int key){
	int l = 0;
	int r = arr.size() - 1;
	int idx = -1;
	while (l <= r){
		int mid = (l + r) / 2;
		if (key <= arr[mid]){
			idx = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return (idx);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> children(n, 0);
	vector<int> dp(n + 1 , 0);
	vector<int> lis;
	for (int i = 0; i < n; i++) {
		cin >> children[i];
		int number = children[i];
		if (lis.size() == 0 || lis.back() < number)
			lis.push_back(number);
		else {
			int pos = find_smallest_bigger_idx(lis, number);
			if (pos != -1){
				lis[pos] = number;
			}
		}
//		for (int i = 0; i < lis.size(); i++) {
//			cout << lis[i] << " ";
//		}
//		cout << "\n";
	}
	cout << n - lis.size();
	return (0);
}

