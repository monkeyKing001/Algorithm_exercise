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
int mod = 1000000;
int err(){
	cout << "0";
	return (0);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> dp_1(5005, 0);
	string n_to_str;
	cin >> n_to_str;
//	string check = to_string(stoi(n_to_str));
//	if (n_to_str != check)
//		return (err());
	dp_1[0] = 1;
	for (int i = 0; i < n_to_str.size(); i++) {
		char cur_char = n_to_str[i];
		if (cur_char == '0') {
			if (i >= 1) {
				char prev_char = n_to_str[i - 1];
				if (prev_char == '1' || prev_char == '2')
					dp_1[i + 1] = dp_1[i - 1];
				else
					return (err());
				//reset prev case num
			}
			else 
				return (err());
		}
		else
			dp_1[i + 1] = dp_1[i];
		if (i >= 1 && cur_char != '0') {
			char prev_char = n_to_str[i - 1];
			if (prev_char == '1') {
				dp_1[i + 1] += dp_1[i - 1];
				dp_1[i + 1] %= mod;
//				cout << "1x\n";
			}
			else if (prev_char == '2' && (cur_char >= '0' && cur_char <= '6')) {
				dp_1[i + 1] += dp_1[i - 1];
				dp_1[i + 1] %= mod;
//				cout << "2x\n";
			}
			if (cur_char == '0' && ( prev_char != '1' && prev_char != '2')) {
//				cout << "0\n";
				return (0);
			}
		}
//		cout << "cur_char, dp : " << cur_char << ", " << dp_1[i + 1] << "\n";
	}
	cout << dp_1[n_to_str.size()] % mod;
	return (0);
}

