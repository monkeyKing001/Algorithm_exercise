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
vector<vector<int>> info(101, vector<int> (1, INT_MAX)); 

struct cmp{
	bool operator()(pair<int, int> bottom, pair<int, int> top){
		return (bottom.second < top.second);
	}
};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<int, int> count;
	set<int> multitab;
	cin >> n >> m;
	vector<int> item(m, 0);
	int change_count = 0;
	for (int i = 0; i < m; i++) {
		int number;
		cin >> number;
		item[i] = number;
	}
	for (int i = item.size() - 1; i >= 0; i--) {
		int item_number = item[i];
		info[item_number].push_back(i);
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int i = 0; i < item.size(); i++) {
		int item_number = item[i];
		info[item_number].pop_back();
//		cout << "item, next appreance idx : " << item_number << ", " << info[item_number].back() << "\n";
		if (multitab.size() == n) {
			//plug out, find victim
			if (multitab.find(item_number) == multitab.end()) {
				int victim = pq.top().first;
//				cout << "victim : " <<  victim << "\n";
				pq.pop();
				multitab.erase(victim);
				change_count++;
			}
		}
		multitab.insert(item_number);
		pq.push({item_number, info[item_number].back()});
	}
	cout << change_count;
	return (0);
}

