#include <queue>
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


#define WEIGHT first
#define PRICE second

#define PRICE_PQ first
#define WEIGHT_PQ second

#define ll long long

using info_w_p = pair<ll, ll>;
using info_p_w = pair<ll, ll>;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<info_p_w, vector<info_p_w>> pq;
	cin >> n >> m;
	vector<info_w_p> gems(n);
	for (int i = 0; i < n; i++) {
		ll w, p;
		cin >> gems[i].WEIGHT;
		cin >> gems[i].PRICE;
	}
	vector<ll> bags(m);
	for (int i = 0; i < m; i++) {
		cin >> bags[i];
	}
	sort(gems.begin(), gems.end());
	sort(bags.begin(), bags.end());
	int gems_i = 0;
	ll total_price = 0;
	for (int i = 0; i < bags.size(); i++) {
		int limit = bags[i];
		while (gems_i < n && gems[gems_i].WEIGHT <= limit){
			pq.push({gems[gems_i].PRICE, gems[gems_i].WEIGHT});
			gems_i++;
		}
		total_price += (ll)(pq.top().PRICE_PQ);
		pq.pop();
	}
	cout << total_price;
	return (0);
}

