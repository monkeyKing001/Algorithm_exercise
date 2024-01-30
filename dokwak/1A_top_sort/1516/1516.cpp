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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<vector<int>>g(n + 1);
	vector<int>indegree(n + 1, 0);
	vector<int>startTime(n + 1, 0);
	vector<int>cost(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int time, token, buildingNum = i + 1;
		cin >> token;
		time = token;
		cost[buildingNum] = time;
		cin >> token;
		while (token != -1){
			int dependency = token;
			indegree[buildingNum]++;
			g[dependency].push_back(buildingNum);
			cin >> token;
		}
	}
	queue<vector<int>> q;
	for (int i = 1; i < n + 1; i++) {
		if (indegree[i] == 0){
			vector<int>info(2);
			info[0] = i;
			info[1] = 0;//startTime
			startTime[i] = 0;
			q.push(info);
		}
	}
	while (q.size() != 0){
		vector<int> info = q.front();
		q.pop();
		int cur = info[0];
		int curStartTime = startTime[cur];
//		int curStartTime = info[1];
		int endTime = curStartTime + cost[cur];
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			indegree[next]--;
			startTime[next] = max(startTime[next], endTime);
			if (indegree[next] == 0){
				vector<int> nextInfo(2);
				nextInfo[0] = next;
				nextInfo[1] = startTime[next];
				q.push(nextInfo);
			}
		}
	}
	for (int i = 1; i < n + 1; i++) {
		cout << startTime[i] + cost[i] << "\n";
	}
	return (0);
}

