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
	set<string> s;
	string input;
	cin >> input;
	for (int i = 0; i < input.length() - 2; i++) {
		string chk1 = input.substr(0, (i - 0) + 1);
		string rchk1(chk1.rbegin(), chk1.rend());
//		cout << "rch1 : " << rchk1 << "\n";
		for (int j = i + 1; j < input.length() - 1; j++) {
			string ch2 = input.substr(i + 1, j - (i + 1) + 1);
			string rch2(ch2.rbegin(), ch2.rend());
			string ch3 = input.substr(j + 1, input.length() - (j + 1));
			string rch3(ch3.rbegin(), ch3.rend());
//			cout << "rch2 : " << rch2 << "\n";
//			cout << "rch3 : " << rch3 << "\n";
			string ent = rchk1 + rch2 + rch3;
			s.insert(ent);
		}
	}
	cout << *s.begin() << "\n";
	return (0);
}

