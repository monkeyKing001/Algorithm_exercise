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
const int ROOT = 1;
int unused = 2;
const int MAX = 10000 * 500 + 5;
vector <bool> check(MAX, false);
vector <vector<int>> g(MAX, vector<int> (26, -1));

int char_to_int(char c) {
	return (c - 'a');
}

void insert(const string &s){
	int cur = ROOT;
	for (auto c : s) {
		if (g[cur][char_to_int(c)] == -1)
			g[cur][char_to_int(c)] = unused++;
		cur = g[cur][char_to_int(c)];
	}
	check[cur] = true;
}

bool find(const string &s){
	int cur = ROOT;
	for (auto c : s) {
		if (g[cur][char_to_int(c)] == -1)
			return false;
		cur = g[cur][char_to_int(c)];
	}
	return (check[cur]);
}

int	main(int argc, char **argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}
	int count = 0;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (find(s))
			count++;
	}
	cout << count;
	return (0);
}

