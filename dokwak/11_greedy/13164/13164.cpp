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
	int k;
	cin >> n >> k;
	int prev_num = 0;
	int num;
	int total_cost = 0;
	priority_queue<int> cost_pq;
	for (int i = 0; i < n; i++){
		cin >> num;
		if (i != 0){
			cost_pq.push(num - prev_num);
			total_cost += num - prev_num;
		}
		prev_num = num;
	}
	while (--k != 0) {
		total_cost -= cost_pq.top();
		cost_pq.pop();
	}
	cout << total_cost;
	return (0);
}

