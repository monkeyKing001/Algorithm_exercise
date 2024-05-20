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
int l = 1;
int r = 1000000000;
int sol = 0;

bool possible(const vector<int> &lec, int mid){
	int count = 0;
	int sumWeight = 0;
	int i = 0;
	int limit = mid;
	while (i < lec.size()) {
		sumWeight = 0;
		count++;
		while (i < lec.size() && sumWeight + lec[i] <= limit) {
			sumWeight += lec[i];
			i++;
		}
		if (count > m)
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector <int> lec (n, 0);
	for (int i = 0; i < n; i++) 
		cin >> lec[i];
	int solSize = r;
	while (l <= r){
		int mid = (l + r) / 2;
//		cout << "trying : " << mid << "\n";
		//try smaller
		if (possible(lec, mid)){
			solSize = mid;
			r = mid - 1;
		}
		//try bigger
		else
			l = mid + 1;
	}
	cout << solSize;
	return (0);
}

