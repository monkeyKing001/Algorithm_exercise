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
	string origin, target;
	string buf = "";
	cin >> origin >> target;
	for (int i = 0; i < origin.length(); i++) {
		char chr = origin[i];
		buf += chr;
		if (chr == target[target.length() - 1]){
			bool made = false;
			for (int j = 0; j < target.length(); j++) {
				int bufIdx = buf.length() - 1 - j;
				int targetIdx = target.length() - 1 - j;
				if (bufIdx < 0)
					break;
				if (buf[bufIdx] != target[targetIdx])
					break;
				if (targetIdx == 0)
					made = true;
			}
			if (made){
				for (int i = 0; i < target.length(); i++) {
					buf.pop_back();
				}
//				cout << "now buf is : "<<  buf << "\n";
			}
		}
	}
	if (buf.length() == 0){
		buf = "FRULA";
	}
	cout << buf;
	return (0);
}

