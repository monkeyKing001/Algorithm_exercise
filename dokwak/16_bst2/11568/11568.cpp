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
int bstLowerBound(vector<int> vec, int key){
	int l = 0;
	int r = vec.size() - 1;
	int idx = -1;
	int mid = (l + r) / 2;
	while (l <= r){
		mid = (l + r) / 2;
		if (vec[mid] < key){
			l = mid + 1;
		}
		else{
			r = mid - 1;
			idx = mid;
		}
	}
	return (idx);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		int idx = bstLowerBound(vec, num);
		if (idx == -1)
			vec.push_back(num);
		else
			vec[idx] = num;
	}
	cout <<vec.size();
	return (0);
}

