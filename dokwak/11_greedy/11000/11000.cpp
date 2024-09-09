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

struct cmp{
	bool operator()(pair<int, int> bottom, pair<int, int> top){
		if (top.second == bottom.second)
			return top.first < bottom.first;
		return top.second < bottom.second;
	}
};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<pair<int, int>> info;
	for (int i = 0; i < n; i++) {
		int start = 0, end = 0;
		cin >> start >> end;
		info.push_back({start, end});
	}
	sort(info.begin(), info.end());
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int i = 0; i < info.size(); i++) {
		int start = info[i].first, end = info[i].second;
		//can allocate
//		if (pq.size() != 0)
//			cout << "cur top end : " << pq.top().second << "\n";
		if (pq.size() != 0 && pq.top().second <= start) 
			pq.pop();
		pq.push({start, end});
	}
	cout << pq.size();
	return (0);
}
