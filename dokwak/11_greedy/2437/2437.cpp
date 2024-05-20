#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>
using namespace std;
vector<int> w;
int sol = -1;
int n, m;

int bst_upperBound(int l, int r, int key){
	int mid = (l + r) / 2;
	int tempIdx = -1;
	while (l <= r){
		mid = (l + r) / 2;
		if (w[mid] <= key){
			tempIdx = mid;
			l = mid + 1;
		}
		else 
			r = mid - 1;
	}
	return (tempIdx);
}

bool bruteBST(int l, int r, int key){
	bool found = false;
	int biggestIdx = bst_upperBound(l, r, key);
	if (key == 0)
		return true;
	if (biggestIdx == -1){
		return false;
	}
//	cout << "[subproblem] lets find " << key << " from l ~ r " << l <<" ~ " << r << "\n"; 
	int curNum = 0;
	while (biggestIdx != 0){
		curNum = w[biggestIdx];
		int nextTarget = key - curNum;
		if (!bruteBST(l, biggestIdx - 1, nextTarget)){
			biggestIdx--;
		}
		else{
			found = true;
			break;
		}
	}
	return (found);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	w.push_back(0);
	for (int i = 0; i < n; i++){
		int num = 0;
		cin >> num;
		w.push_back(num);
	}
	sort(w.begin(), w.end());
	for (int i = 1; i <= 1000000000 && sol == -1; i++) {
		int target = i;
//		cout << "target num is " << target << "\n";
		if (!bruteBST(0, w.size() - 1, target))
			sol = target;
	}
	cout << sol;
	return (0);
}
