#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m, k;

bool cmp (pair<int, int >e1, pair<int, int>e2){
	if (e1.second == e2.second){
		return (e1.first < e2.first);
	}
	return (e1.second > e2.second);
}

int bst(const deque<int> &k, int key){
	int idx = -1;
	int l = 0, r = k.size() - 1; 
	while (l <= r){
		int mid = (l + r) / 2;
		if (k[mid] < key){
			l = mid + 1;
		}
		else {
			r = mid - 1;
			idx = mid;
		}
	}
	return (idx);
}
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	vector<pair<int, int>> jewels(n, {0, 0});
	deque<int> knaps(k, 0);
	multiset<int> knaps_multiset;
	for (int i = 0; i < n; i++) {
		int m_i, v_i;
		cin >> m_i >> v_i;
		jewels[i].first = m_i;
		jewels[i].second = v_i;
	}
	for (int i = 0; i < k; i++){
		cin >> knaps[i];
		knaps_multiset.insert(knaps[i]);
	}
	sort(jewels.begin(), jewels.end(), cmp);
	sort(knaps.begin(), knaps.end());
	long long sol = 0;
	for (int i = 0; i < jewels.size() && knaps.size() != 0; i++) {
		int m_i = jewels[i].first;
		int v_i = jewels[i].second;
		int idx = bst(knaps, m_i);
		if (idx != -1) {
			sol += (long long) v_i;
			knaps.erase(knaps.begin() + idx);
		}
	}
	cout << sol;
	return (0);
}

