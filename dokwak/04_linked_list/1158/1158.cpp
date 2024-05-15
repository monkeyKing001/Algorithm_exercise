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
	queue<int> q;
	queue <int> sol;
	int head = 0;
	int k;
	cin >> n >> k; 
	int count = 1;
	for (int i = 1; i < n + 1; i++)
		q.push(i);
	while (!q.empty()){
		int curNum = q.front();
		q.pop();
		if (count == k){
			sol.push(curNum);
			count = 0;
		}
		else
			q.push(curNum);
		count++;
	}
	cout << "<";
	while (!sol.empty()){
		cout << sol.front();
		sol.pop();
		if (sol.empty())
			break;
		cout << ", ";
	}
	cout << ">";
	return (0);
}

