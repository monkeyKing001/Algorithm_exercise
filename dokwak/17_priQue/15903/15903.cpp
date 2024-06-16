#include <queue>
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll num = 0;
		cin >> num;
		pq.push(num);
	}
	ll sol = 0;
	while (m > 0){
		ll num1 = pq.top();
		pq.pop();
		ll num2 = pq.top();
		pq.pop();
		ll newNum = num1 + num2;
		m--;
		pq.push(newNum);
		pq.push(newNum);
	}
	while (pq.size() != 0){
		sol += pq.top();
		pq.pop();
	}
	cout << sol;
	return (0);
}

