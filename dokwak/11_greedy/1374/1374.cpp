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
struct topEndTimeSmaller{
	bool operator()(vector<int> bottom, vector<int>top){
		if (bottom[2] == top[2])
			return (bottom[1] > top[1]);
		return(bottom[2] > top[2]);
	}
};

bool compare(vector<int> v1, vector<int>v2){
	if (v1[1] == v2[1])
		return (v1[2] < v2[2]);
	return (v1[1] < v2[1]);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<vector<int>> vec;
	priority_queue<vector<int>, vector<vector<int>>, topEndTimeSmaller> pq;
	for (int i = 0; i < n; i++) {
		vector<int>info(3);
		cin >> info[0] >> info[1] >> info[2];
		vec.push_back(info);
	}
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < n; i++) {
		vector<int>info = vec[i];
		int start = info[1];
		int end = info[2];
		if (pq.size() != 0 && pq.top()[2] <= start)
			pq.pop();
		pq.push(info);
	}
	cout << pq.size();
	return (0);
}

