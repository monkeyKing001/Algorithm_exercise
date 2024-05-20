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
long long sol = 0;

int bst(vector<int> &f, int k, int startIdx){
	int ret = -1;
	int l = startIdx + 1;
	int r = f.size() - 1;
	//if (files[mid] <= k) check range.
	while (l <= r){
		int mid = (l + r) / 2;
		if (f[mid] <= k){
			ret = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> files(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> files[i];
	}
	sort(files.begin(), files.end());
	for (int i = 0; i < n - 1; i++) {
		int startIdx = i;
		int checkFileSize = files[startIdx] * 10 / 9;
		int checkIdx = bst(files, checkFileSize, startIdx);
//		cout << "file idx, checkIdx : " << startIdx << ", " << checkIdx<< "\n";
		sol += max((long long)0, ((long long)checkIdx - (long long)startIdx));
	}
	cout << sol;
	return (0);
}
