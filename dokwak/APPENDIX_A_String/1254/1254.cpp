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
bool isPalindrome(string str, int start, int last){
	int l = start;
	int r = last;
	while (l <= r){
		if (str[l] == str[r]){
			l++;
			r--;
		}
		else
			return false;
	}
	return true;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> str;
	int lastPalindIdx =  str.length() - 1;
	int idx = str.length() - 1;
	while (idx >= 0){
		if (isPalindrome(str, idx, str.length() - 1))
			lastPalindIdx = idx;
		idx--;
	}
	cout << str.length() + lastPalindIdx;
	return (0);
}

