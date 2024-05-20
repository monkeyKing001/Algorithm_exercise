#include <queue>
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
int c;

bool possible(vector<int> &arr, int k){
	int restRouter = c;
	int prev = arr[0];
	int idx = 1;
	restRouter--;
	while (restRouter > 0 && idx < arr.size()){
		if (arr[idx] - prev >= k){
			prev = arr[idx];
			restRouter--;
		}
		idx++;
	}
	if (restRouter > 0)
		return false;
//	cout << "success margin : " << k << "\n";
//	cout << "nearest distance : " << pq.top() << "\n";
	return (true);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	c = m;
	vector<int> house(n, 0);
	for (int i = 0; i < n; i++) 
		cin >> house[i];
	sort(house.begin(), house.end());
	int l = 0;
	int r = 1000000000;
	int mid = (l + r) / 2;
	int tempSol = l;
	while (l <= r){
		mid = (l + r) / 2;
		if (possible(house, mid)){ //make margin bigger
			l = mid + 1;
			tempSol = mid;
		}
		else
			r = mid - 1; //make margin smaller
	}
	cout << tempSol;
	return (0);
}
