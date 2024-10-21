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
	priority_queue<int, vector<int>, greater<int>> ascending_num;
	priority_queue<int, vector<int>, less<int>> descending_num;
	cin >> n;
	int min_num = -110000;
	int max_num = 110000;
	int median = min_num;
	ascending_num.push(max_num);
	descending_num.push(min_num);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num >= descending_num.top())
			ascending_num.push(num);
		else
			descending_num.push(num);
		while (ascending_num.size() > descending_num.size()){
			int move_num = ascending_num.top();
			descending_num.push(move_num);
			ascending_num.pop();
		}
		while (descending_num.size() - 1 > ascending_num.size()){
			int move_num = descending_num.top();
			ascending_num.push(move_num);
			descending_num.pop();
		}
		median = descending_num.top();
		cout << median << "\n";
	}
	return (0);
}

