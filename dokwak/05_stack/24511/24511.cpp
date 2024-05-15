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
	int arr[n];
	vector<int> info(n, 0);
	deque<int> deq;
	for (int i = 0; i < n; i++)
		cin >> info[i];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (info[i] == 0)
			deq.push_back(arr[i]);
	}
	int operNum = 0;
	cin >> operNum;
	for (int i = 0; i < operNum; i++) {
		int curNum;
		cin >> curNum;
		deq.push_front(curNum);
		curNum = deq.back();
		deq.pop_back();
		cout << curNum << " ";
	}
	return (0);
}

