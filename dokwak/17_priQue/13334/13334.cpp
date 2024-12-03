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
#define ll long long
using s_e = pair<ll, ll>;
using e_s = pair<ll, ll>;
#define END first
#define START second

#define START_PQ first
#define END_PQ second

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<e_s> info(n);
	for (int i = 0; i < n; i++) {
		ll h, o;
		cin >> h >> o;
		info[i].START = min(h, o);
		info[i].END = max(h, o);
	}
	ll rail_length = 0;
	cin >> rail_length;
	int sol = 0;
	sort(info.begin(), info.end());
	priority_queue<s_e, vector<s_e>, greater<s_e>> pq;
	for (int i = 0; i < info.size(); i++) {
		auto [end, start] = info[i];
		ll rail_end = end;
		ll rail_start = rail_end - rail_length;
		if (start >= rail_start)
			pq.push({start, end});
		while (pq.size() != 0 && pq.top().START_PQ < rail_start)
			pq.pop();
		sol = max(sol, (int)pq.size());
	}
	cout << sol;
	return (0);
}

