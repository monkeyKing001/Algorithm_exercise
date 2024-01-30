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
	int T;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++) {
		cin >> n;
		vector<int> vec(n);
		vector<int> rearr(n);
		for (int i = 0; i < n; i++) {
			cin >> vec[i];
		}
		sort(vec.begin(), vec.end());
		int l = 0, r = n - 1, idx = 0;
		while (l <= r){
			rearr[l] = vec[idx++];
			l++;
			if (idx == n)
				break;
			rearr[r] = vec[idx++];
			r--;
		}
		int maxDiff = abs(rearr[0] - rearr[n - 1]);
		for (int i = 1; i < n; i++) {
			maxDiff = max(maxDiff, abs(rearr[i - 1] - rearr[i]));
		}
		cout << maxDiff << "\n";
	}
	return (0);
}

