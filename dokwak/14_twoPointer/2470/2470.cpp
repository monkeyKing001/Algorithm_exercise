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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> solutions(n, -1);
	for (int i = 0; i < n; i++) 
		cin >> solutions[i];
	sort(solutions.begin(), solutions.end());
	int tempL = -1, tempR = -1, tempSol = INT_MAX;
	int l = 0;
	int r = solutions.size() - 1;
	while (l < r){
		int sum = solutions[l] + solutions[r];
		if (tempSol > abs(sum)) {
			tempL = solutions[l];
			tempR = solutions[r];
			tempSol = abs(sum);
		}
		if (sum > 0)
			r--;
		else if (sum < 0)
			l++;
		else if (sum == 0)
			break;
	}
	cout << tempL << " " << tempR;
	return (0);
}

