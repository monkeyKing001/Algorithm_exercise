#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	for (int i = 0; i < n; ++i) {
		int input;
		cin >> input;
		if (max_pq.empty() || input < max_pq.top())
			max_pq.push(input);
		else
			min_pq.push(input);
		if ((int)max_pq.size() - (int)min_pq.size() > 1) {
			min_pq.push(max_pq.top());
			max_pq.pop();
		}
		else if ((int)min_pq.size() - (int)max_pq.size() > 0) {
			max_pq.push(min_pq.top());
			min_pq.pop();
		}
		cout << max_pq.top() << '\n';
	}
	return (0);
}

