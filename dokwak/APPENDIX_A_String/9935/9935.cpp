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
	string origin, bomb;
	string buf = "";
	cin >> origin >> bomb;
	for (int i = 0; i < origin.length(); i++) {
		char cur_char = origin[i];
		buf.push_back(cur_char);
		if (buf.back() == bomb.back()){
			//check bomb
			bool bomb_made = false;
			int cur_i = buf.size() - 1;
			for (int j = 0; j < bomb.size() && cur_i - j >= 0; j++) {
				if (bomb[bomb.size() - 1 - j] != buf[cur_i - j])
					break;
				if (j == bomb.size() - 1)
					bomb_made = true;
			}
			if (bomb_made){
				for (int i = 0; i < bomb.size(); i++) 
					buf.pop_back();
			}
		}
	}
	if (buf.length() == 0){
		buf = "FRULA";
	}
	cout << buf;
	return (0);
}

