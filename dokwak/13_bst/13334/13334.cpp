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
#define START first
#define END second
#define ll long long
ll d;

struct cmp{
	bool operator()(pair<ll, ll> bottom, pair<ll, ll> top){
		if (bottom.END == top.END)
			return (top.START < bottom.START);
		return (bottom.END > top.END);
	}
};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int sol = 0;
	vector<pair<ll, ll>> info(n);
	for (int i = 0; i < n; i++) {
		ll start, end;
		cin >> start >> end;
		info[i].START = min(start, end);
		info[i].END = max(start, end);
	}
	cin >> d;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> in;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> candidates;
	sort(info.begin(), info.end());
	ll r = 0;
	for (int i = 0; i < info.size(); i++) {
		ll start_position = info[i].START;
		ll window_end_position = start_position + d;
//		cout << "##investication star, end : " << start_position << ", " << window_end_position << "\n";
		while (r < info.size() && info[r].START <= window_end_position){
			ll length = info[r].END - info[r].START;
			if (length <= d){
				if (info[r].END <= window_end_position){
					in.push(info[r]);
//					cout << "found include start, end : " << info[r].START << ", " << info[r].END << "\n";
				}
				else{
					candidates.push(info[r]);
//					cout << "candidates start, end : " << info[r].START << ", " << info[r].END << "\n";
				}
			}
			r++;
		}
		//include
		while (candidates.size() > 0 && candidates.top().END <= window_end_position){
//			cout << "from candidates to in group start, end : " << candidates.top().START << ", " <<  candidates.top().END << "\n";
			in.push(candidates.top());
			candidates.pop();
		}
		//exclude
		while (in.size() > 0 && in.top().START < start_position){
//			cout << "exclude in group start, end : " << in.top().START << ", " <<  in.top().END << "\n";
			in.pop();
		}
		sol = max(sol, (int)in.size());
	}
	cout << sol;
	return (0);
}
