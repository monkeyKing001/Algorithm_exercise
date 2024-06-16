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
		if (bottom.first == top.first)
			return (bottom.second - bottom.first > top.second - top.first);
		return (bottom.first > top.first);
	}
};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		pq.push({start, end});
	}
	vector<pair<int, int>> classes;
	while (pq.size() != 0){
		int start = pq.top().first;
		int end = pq.top().second;
		pq.pop();
		if (classes.size() == 0){
			classes.push_back({start, end});
		}
		else{
			int prvStart = classes.back().first;
			int prvEnd = classes.back().second;
			if (prvEnd <= start){
				classes.push_back({start, end});
			}
			else if (prvEnd > end){
				classes.pop_back();
				classes.push_back({start, end});
			}
		}
	}
//	for (int i = 0; i < classes.size(); i++) {
//		cout << "start, end : " << classes[i].first << ", " << classes[i].second << "\n"; 
//	}
	cout << classes.size();
	return (0);
}
