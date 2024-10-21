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
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	int sol = 0;
	while (pq.size() > 1){
		int top1 = pq.top();
		pq.pop();
		int top2 = pq.top();
		pq.pop();
		int sum = top1 + top2;
		sol += sum;
		pq.push(sum);
	}
	cout << sol;
	return (0);
}

