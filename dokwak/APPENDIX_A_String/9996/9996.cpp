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
	cin >> n;
	string pattern;
	cin >> pattern;
	int delIdx = 0;
	delIdx = pattern.find("*");
	string start = pattern.substr(0, delIdx);
	string end = pattern.substr(delIdx + 1, pattern.length());
//	cout << "start : " << start << "\n";
//	cout << "end : " << end << "\n";
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str.length() >= start.length() + end.length()
				&& str.find(start) == 0 
				&& str.rfind(end) == str.length() - end.length()){
			cout << "DA\n";
		}
		else{
			cout << "NE\n";
		}
	}
	cout.tie(0);
	return (0);
}

