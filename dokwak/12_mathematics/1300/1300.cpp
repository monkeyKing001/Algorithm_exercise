#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
ll n, m;

bool valid(ll k){
//	cout << "trying k = " << k << "\n";
	ll count = 0;
	for (int i = 1; i <= n; i++) {
		ll modCount = k / i;
		count += min(modCount, n);
//		cout << "row i : " << i << " ";
//		cout << "adding " << min(modCount, n) << "\n";
		if (count >= m){
			return true;
		}
	}
//	cout << "false\n";
	return (false);
}

int	main(int argc, char **argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	ll l = 1;
	ll r = n * n;
	ll target = m;
	ll sol = r;
	while (l <= r){
		ll mid = (l + r) / 2;
		if (valid(mid)){
			r = mid - 1;
			sol = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << sol;
	return (0);
}
