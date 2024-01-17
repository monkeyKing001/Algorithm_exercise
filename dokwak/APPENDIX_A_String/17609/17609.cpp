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
int sol = INT_MAX;
int maxChance = 2;
void rec(string str, int l, int r, int chance){
	if (chance >= maxChance || sol < maxChance){
		return;
	}
	else {
//		cout << "str, l, r : " << str <<", " << l << ", "<< r << "\n";
		while (l <= r){
			if (str[l] != str[r]){
				rec(str, l + 1, r, chance + 1);
				rec(str, l, r - 1, chance + 1);
				break;
			}
			else {
				l++;
				r--;
			}
		}
		if (l > r){
			sol = chance;
		}
	}
}
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		sol = INT_MAX;
		cin >> str;
//		cout << "str check : " << str << "\n";
		rec(str, 0, str.length() - 1, 0);
		sol = min(2, sol);
		cout << sol << "\n";
	}
	return (0);
}

