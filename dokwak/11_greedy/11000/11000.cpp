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

struct smallerTopSecondCmp{
	bool operator()(pair<int, int> bottom, pair<int, int> top){
		if (top.second == bottom.second){
			return (top.first < bottom.second);
		}
		return (top.second < bottom.second);
	}
};

bool cmp(pair<int, int> e1, pair<int, int> e2){
	if (e1.first == e2.first)
		return (e1.second < e2.second);
	return (e1.first < e2.first);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<pair<int, int>, vector<pair<int, int>>, smallerTopSecondCmp>pq;
	vector<pair<int, int>> info;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		info.push_back({start, end});
	}
	sort(info.begin(), info.end(), cmp);
	for (int i = 0; i < info.size(); i++) {
		int start = info[i].first;
		int end = info[i].second;
		if (pq.size() != 0 && pq.top().second <= start)
			pq.pop();
		pq.push({start, end});
	}
	cout << pq.size();
	return (0);
}
