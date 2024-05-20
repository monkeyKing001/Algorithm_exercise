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
	cin >> n >> m;
	int h = m;
	vector<int> up(m + 1, 0);
	vector<int> down(m + 1, 0);
	for (int i = 0; i < n; i++) {
		int height = 0;
		cin >> height;
		if (i % 2 == 0)
			up[h - height + 1]++;
		else
			down[height]++;
	}
	vector<int> upPrefixSum(m + 1, 0);
	vector<int> downPrefixSum(m + 1, 0);
	downPrefixSum[m] = down[m];
	for (int i = m - 1; i >= 1; i--){
		downPrefixSum[i] = down[i] + downPrefixSum[i + 1];
	}
	for (int i = 1; i <= m; i++) {
		upPrefixSum[i] = upPrefixSum[i - 1] + up[i];
	}
	int breakNum = INT_MAX;
	map<int, int> breakInfoMap;
	for (int i = 1; i <= m; i++) {
		int tempBreakNum = downPrefixSum[i] + upPrefixSum[i];
		breakInfoMap[tempBreakNum]++;
	}
	cout << breakInfoMap.begin() -> first << " ";
	cout << breakInfoMap.begin() -> second;
	//upPrefixSum -> increase with index
	//downPrefixSum -> decrease with index
	return (0);
}
