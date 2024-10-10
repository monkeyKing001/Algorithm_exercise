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
int ROOT = 1;
int unused = 2;
const int MAX = 10000 * 500 + 5;
vector<bool> check_end(MAX, false);
vector<vector<int>> g(MAX, vector<int> (26, -1));

int char_to_int(char c) {
	return (c - 'a');
}

void insert(const string &s) {
	int cur = ROOT;
	for (auto c : s){
		if (g[cur][char_to_int(c)] == -1){
			g[cur][char_to_int(c)] = unused;
			unused++;
		}
		cur = g[cur][char_to_int(c)];
	}
	check_end[cur] = true;
}

bool prefix_check(const string &s) {
	int cur = ROOT;
	bool find = true;
	for (auto c : s){
		if (g[cur][char_to_int(c)] == -1){
			find = false;
			break;
		}
		cur = g[cur][char_to_int(c)];
	}
	return (find);
}

int	main(int argc, char **argv)
{
	int sol = 0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (prefix_check(s))
			sol++;
	}
	cout << sol;
	return (0);
}

