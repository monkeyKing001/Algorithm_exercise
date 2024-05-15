#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<deque<int>> arr(21);
	int k = 0;
	ll sol = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		int len = name.length();
		while (arr[len].size() != 0 && abs(arr[len].front() - i) > k){
			sol += (arr[len].size() - 1);
//			cout << "poping : " << arr[len].front() << "\n";
			arr[len].pop_front();
		}
		arr[len].push_back(i);
	}
	for (int i = 1; i < 21; i++) {
		if (arr[i].size() > 1){
			sol += ((ll)arr[i].size() * (ll)(arr[i].size() - 1)) / (ll)2;
		}
	}
	cout << sol;
	return (0);
}

