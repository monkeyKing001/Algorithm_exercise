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
#define NEXT_USE_TIME front()
#define next_use_time first
#define device_num second
using evict_device = pair<int, int>;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int k = m;
	set<int> plug_in;
	vector<deque<int>> plugs(k + 1); 
	vector<int> info(k, 0);
	int count = 0;
	for (int i = 0; i < k; i++) {
		cin >> info[i];
		int device_num = info[i];
		plugs[device_num].push_back(i);
	}
	for (int i = 1; i < k + 1; i++)
		plugs[i].push_back(INT_MAX);
	priority_queue<evict_device> pq;
	for (int i = 0; i < k; i++){
		int device_num = info[i];
		//need plug out
		if (plug_in.size() == n && plug_in.find(device_num) == plug_in.end()){
			auto [next_time, dev_num] = pq.top();
			pq.pop();
			plug_in.erase(dev_num);
			count++;
		}
		plugs[device_num].pop_front();
		pq.push({plugs[device_num].NEXT_USE_TIME, device_num});
		plug_in.insert(device_num);
	}
	cout << count;
	return (0);
}

