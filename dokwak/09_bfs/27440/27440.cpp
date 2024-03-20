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
#define ll long long

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll num;
	cin >> num;
	queue<pair<ll, ll>> q;
	q.push({1, 0});
	set<ll> s;
	ll sol = INT_MAX;
	while (!q.empty() && sol == INT_MAX) {
		ll curNum = q.front().first;
		ll curStep = q.front().second;
//		cout << "curNum : " << curNum << "\n";
		q.pop();
		if (curNum == num)
			sol = curStep;
		for (int i = 0; i < 3; i++) {
			ll nextNum;
			if (i == 0 && (curNum + 1 <= num))
				nextNum = curNum + 1;
			else if (i == 1 && (curNum * 2 <= num))
				nextNum = curNum << 1;
			else if (i == 2 && (curNum * 3 <= num))
				nextNum = curNum * 3;
			if (s.find(nextNum) != s.end())
				continue;
			q.push({nextNum, curStep + 1});
			s.insert(nextNum);
		}
	}
	cout << sol;
	return (0);
}

