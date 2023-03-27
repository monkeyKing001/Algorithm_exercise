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
int n;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int time;
		cin >> time;
		pq.push(time);
	}
	int sol = 0;
	for (int i = 0; i < n; i++)
	{
		int waiting_time_for_people = pq.size() * pq.top();
		sol += waiting_time_for_people;
		pq.pop();
	}
	cout << sol;
	return (0);
}

