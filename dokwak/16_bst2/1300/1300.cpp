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
ll n, m, k;
bool inRange(ll target){
	ll count = 0;
	for (int i = 1; i < n + 1; i++)
		count += min(target / (ll)i, n);
	if (count >= k)
		return (true);
	return (false);
}

int	main(int argc, char **argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	k = m;
	ll l = 1;
	ll r = k;
	ll temp = -1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (inRange(mid)){
			temp = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << temp;
	return (0);
}

