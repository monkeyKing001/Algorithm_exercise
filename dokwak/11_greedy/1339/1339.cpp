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
bool cmp(pair<char, int>& e1, pair<char, int>& e2){
	return (e2.second < e1.second);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<char, int> score;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
//		cout << str << "\n";
		for (int j = 0; j < str.length(); j++) {
			char chr = str[j];
			score[chr] += pow(10, str.length() - 1 - j);
		}
	}
	vector<pair<char, int>> vec;
	map<char, int>::iterator it = score.begin();
	while (it != score.end()){
//		cout << "char, score : " << it ->first << ", " << it -> second << "\n";
		vec.push_back(*it);
		it++;
	}
	sort(vec.begin(), vec.end(), cmp);
//	cout << "after sorting\n";

	int digit = 9;
	int sol = 0;
	for (int i = 0; i < vec.size(); i++) {
//		cout << "char, score : " << vec[i].first << ", " << vec[i].second << "\n";
		sol += (digit * vec[i].second);
		digit--;
	}
	cout << sol << "\n";
	return (0);
}

