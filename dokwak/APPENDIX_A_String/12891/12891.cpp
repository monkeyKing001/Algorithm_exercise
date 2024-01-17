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
int need[4];
int curUse[4];
int sol = 0;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	string str;
	cin >> str;
	for (int i = 0; i < 4; i++) {
		cin >> need[i];
		//cout << need[i] << " ";
	}
	for (int i = 0; i < str.length(); i++) {
		char chr = str[i];
		if (chr == 'A')
			curUse[0]++;
		if (chr == 'C')
			curUse[1]++;
		if (chr == 'G')
			curUse[2]++;
		if (chr == 'T')
			curUse[3]++;
		//minus
		if (i >= m){
			char lastChar = str[i - m];
			if (lastChar == 'A')
				curUse[0]--;
			if (lastChar == 'C')
				curUse[1]--;
			if (lastChar == 'G')
				curUse[2]--;
			if (lastChar == 'T')
				curUse[3]--;
		}
		//check
		if (i >= m - 1){
			for (int i = 0; i < 4; i++) {
				if (need[i] > curUse[i])
					break;
				if (i == 3)
					sol++;
			}
		}
	}
	cout << sol;
	return (0);
}
