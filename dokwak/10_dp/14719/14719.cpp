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
	cin >> n >> m;
	vector<int> vec(m);
	vector<int> leftDp(m);
	vector<int> rightDp(m);
	vector<int> rainDp(m);
	for (int i = 0; i < m; i++) {
		cin >> vec[i];
	}
	int tempMax = 0;
	for (int i = 0; i < m; i++) {
		tempMax = max(tempMax, vec[i]);
		leftDp[i] = tempMax;
	}
	tempMax = 0;
	for (int i = 0; i < m; i++) {
		tempMax = max(tempMax, vec[vec.size() - 1 - i]);
		rightDp[vec.size() - 1 - i] = tempMax;
	}
	for (int i = 0; i < m; i++) {
		int lowestBoundary = min(leftDp[i], rightDp[i]);
		rainDp[i] = max(0, lowestBoundary - vec[i]);
	}
//	printOneDVec(vec);
//	printOneDVec(leftDp);
//	printOneDVec(rightDp);
//	printOneDVec(rainDp);
	int sol = accumulate(rainDp.begin(), rainDp.end(), 0);
	cout << sol;
	return (0);
}

