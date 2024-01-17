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
	set<string> s;
	vector<string> book;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		book.push_back(str);
	}
	for (int len = 1; len < n + 1; len++) {
		s.clear();
		for (int s_i = 0; s_i < n; s_i++) {
			string str = book[s_i];
			string substr = str.substr(str.length() - len, len);
//			cout << substr << "\n";
			s.insert(substr);
		}
//		cout << "size : "<< s.size() << "\n";
		if (s.size() == book.size()) {
			cout << len;
			return(0);
		}
	}
	cout << book[0].length();
	return (0);
}

