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
bool cmp(string e1, string e2){
	//if same size, lexi sort
	if (e1.size() == e2.size()){
		return (e1 < e2);
	}
	return (e1.size() < e2.size());
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	set<string> set_num_str;
	vector<string> vec_num_str;
	vector<string> arr_str(n);
	for (int i = 0; i < n; i++)
		cin >> arr_str[i];
	for (int i = 0; i < n; i++) {
		string str = arr_str[i];
		int l = 0;
		while (l < str.size()) {
			while (l < str.size() && !isdigit(str[l]))
				l++;
			int r = l + 1;
			while (r < str.size() && isdigit(str[r]))
				r++;
//			cout << "l, r : " << l << ", "<< r << "\n";
			if (l < str.size()){
				string temp_num_str = str.substr(l, (r - l));
				while (l < str.size() && str[l] == '0')
					l++;
				string num_erased_first_zero = (l == r) ? "0" : str.substr(l, (r - l));
				set_num_str.insert(num_erased_first_zero);
				vec_num_str.push_back(num_erased_first_zero);
//				cout <<"str num : "<< temp_num_str << "\n";
//				cout << num << "\n";
			}
			l = r;
		}
	}
	sort(vec_num_str.begin(), vec_num_str.end(), cmp);
	for (auto s : vec_num_str){
		cout << s << "\n";
	}
	return (0);
}

