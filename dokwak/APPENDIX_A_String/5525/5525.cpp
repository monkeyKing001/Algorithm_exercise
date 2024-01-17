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
int sol = 0;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	string target = "";
	string str;
	cin >> str;
	for (int i = 0; i < (2 * n) + 1; i++) {
		char chr = i % 2 == 0 ? 'I' : 'O';
		target += chr;
	}
	//cout << target;
	if (m < target.length())
		sol = 0;
	else{
		for (int i = 0; i + target.length() <= str.length(); i++) {
			string substr = str.substr(i, target.length());
			if (substr == target)
				sol++;
		}
	}
	cout << sol;
	return (0);
}

