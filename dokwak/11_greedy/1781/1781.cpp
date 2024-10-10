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
	int cur_time = 0;
	long long sol = 0;
	vector<vector<long long>> info(n + 1);
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; i++) {
		int dead_line, ramen;
		cin >> dead_line >> ramen;
		info[dead_line].push_back(ramen);
	}
	for (int i = 0; i < n + 1; i++) {
		if (info[i].size() == 0)
			continue;
		sort(info[i].rbegin(), info[i].rend());
		for (int j = 0; j < info[i].size(); j++) {
			if (pq.size() < i)
				pq.push(info[i][j]);
			else{
				if (pq.top() < info[i][j]){
					pq.pop();
					pq.push(info[i][j]);
				}
				else
					break;
			}
		}
	}
	while (pq.size() != 0){
		sol += pq.top();
		pq.pop();
	}
	cout << sol;
	return (0);
}

