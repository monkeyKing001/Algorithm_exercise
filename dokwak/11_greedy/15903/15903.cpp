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
	cin >> n >> m;
	vector<int> v(n , 0);
	sort(v.begin(), v.end());
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push((ll)num);
	}
	while (m > 0){
		ll n1 = pq.top();
		pq.pop();
		ll n2 = pq.top();
		pq.pop();
		ll newNum = n1 + n2;
//		cout << "n1, n2 : " << n1 << ", " << n2 << "\n";
		pq.push(newNum);
		pq.push(newNum);
		m--;
	}
	ll sol = 0;
	while (pq.size() != 0){
		sol += (ll) pq.top();
		pq.pop();
	}
	cout << sol;
	return (0);
}
