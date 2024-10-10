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
	string input;
	cin >> input;
	int count = 1;
	while (input[0] != '-'){
		int sol = 0;
		stack <char> open;
		stack <char> close;
		for (int i = 0; i < input.size(); i++) {
			char cur_char = input[i];
			if (cur_char == '{')
				open.push(cur_char);
			else if (cur_char == '}'){
				//stable
				if (open.size() != 0)
					open.pop();
				//unstable
				else
					close.push(cur_char);
			}
		}
		sol += (open.size() / 2) + (open.size() % 2);
		sol += (close.size() / 2) + (close.size() % 2);
		cout << count <<  ". " << sol << "\n";
		cin >> input;
		count++;
	}
	return (0);
}

