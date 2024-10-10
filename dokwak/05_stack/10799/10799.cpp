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
	stack<char> s; 
	long long sol = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char cur_char = str[i];
		if (cur_char == '('){
			s.push('(');
		}
		else if (cur_char == ')'){
			s.pop(); //pop laser start;
			//if laser
			if (str[i - 1] == '('){
//				cout << "laser add : " << s.size() << "\n";
				sol += s.size();
			}
			else{
				sol += 1;
				//else if end of pipe
//				cout << "pipe end add : " << s.size() << "\n";
			}
		}
	}
	cout << sol << "\n";
	return (0);
}

