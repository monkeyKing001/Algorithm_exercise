#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m, k;
bool possible(int target){
	int count = 0;
	for (int i = 1; i <= n; i++){
		count += min((target / i), n);
	}
	return (count >= k);
}

int	main(int argc, char **argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	k = m;
	int l = 0, r = k;
	int temp = -1;
	while (l <= r){
		int mid = (l + r) / 2;
		if (possible(mid)){
			r = mid - 1;
			temp = mid;
		}
		else 
			l = mid + 1;
	}
	cout << temp;
	return (0);
}

