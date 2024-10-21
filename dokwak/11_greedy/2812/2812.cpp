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
	int k;
	cin >> n >> k;
	string str;
	cin >> str;
	stack<char> s;
	vector<char> s_vec;
	for (int i = 0; i < str.size(); i++) {
		char cur_char = str[i];
		//compare with prev char
		if (s_vec.size() != 0) {
			while (s_vec.size() != 0 && s_vec.back() < cur_char && k > 0) {
				s_vec.pop_back();
				k--;
			}
		}
		s_vec.push_back(cur_char);
	}
	stack<char> s_rev;
	while (k-- > 0)
		s_vec.pop_back();
	string buf;
	for (int i = 0; i < s_vec.size(); i++) {
		buf.push_back(s_vec[i]);
	}
	cout << buf;
	return (0);
}

