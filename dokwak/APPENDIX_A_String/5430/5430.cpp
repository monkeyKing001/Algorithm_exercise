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
	int T = 0;
	cin >> T;
	for (int t_i = 0; t_i < T; t_i++) {
		string cmd;
		cin >> cmd;
		int num = 0;
		cin >> num;
		string arr;
		cin >> arr;
		arr = arr.erase(0, 1);
		arr = arr.erase(arr.size() - 1, 1);
		deque<int> deq;
		stringstream ss(arr);
		string tok;
		for (int i = 0; i < num; i++) {
			getline(ss, tok, ',');
//			cout << "tok : " << tok<< "\n";
			int tokToInt = stoi(tok);
			deq.push_back(tokToInt);
		}
		bool seqOrd = true;
		bool err = false;
		for (int i = 0; i < cmd.size() && !err; i++) {
			if (cmd[i] == 'D'){
				if (deq.empty())
					err = true;
				if (!err && seqOrd)
					deq.pop_front();
				else if (!err && !seqOrd)
					deq.pop_back();
			}
			else if (cmd[i] == 'R')
				seqOrd = 0 == seqOrd;
		}
		string sol = "[";
		if (err)
			sol = "error\n";
		else{
			if (seqOrd){
				while (deq.size() != 0){
					sol += to_string(deq.front());
					sol += ',';
					deq.pop_front();
					if (deq.size() == 0)
						sol.pop_back();
				}
			}
			else{
				while (deq.size() != 0){
					sol += to_string(deq.back());
					sol += ',';
					deq.pop_back();
					if (deq.size() == 0)
						sol.pop_back();
				}
			}
			sol += "]\n";
		}
		cout << sol;
	}
	return (0);
}

