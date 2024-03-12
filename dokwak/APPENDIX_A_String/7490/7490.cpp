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
vector<string> sol[10];

void calculate(string str){
	int step = stoi(str.substr(str.length() - 1, 1));
	string token = "";
	string originStr = str;
	while (str.find_first_of(" ") != string::npos){
		str = str.replace(str.find_first_of(" "), 1, "");
	}
//	cout << "replace str : " + str << "\n";
	stack<int> s;
	string prevOperator = "+";
	s.push(0);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+' || str[i] == '-'){
			int madeNum = stoi(token);
			int prevNum = s.top();
			int nextNum = 0;
			s.pop();
			if (prevOperator == "+"){
				nextNum = prevNum + madeNum;
			}
			else if (prevOperator == "-"){
				nextNum = prevNum - madeNum;
			}
			s.push(nextNum);
			prevOperator = str[i];
			token = "";
		}
		else if (str[i] == ' '){
			continue ;
		}
		else if (isdigit(str[i])){
			token += str[i];
			if (i == str.length() - 1){
				int madeNum = stoi(token);
				int prevNum = s.top();
				int nextNum = 0;
				s.pop();
				if (prevOperator == "+"){
					nextNum = prevNum + madeNum;
				}
				else if (prevOperator == "-"){
					nextNum = prevNum - madeNum;
				}
				s.push(nextNum);
			}
		}
	}
	if (s.top() == 0){
		sol[step].push_back(originStr);
	}
	string test = to_string(s.top());
	string subStr = test.substr(0, test.length());
	string test2 = test.replace(test.find_first_of("test"), 4, "tttt");
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	map<int, string> m[10];
	vector<string> allCase[10];
	vector<string> operatorChar = {"+" , " ", "-"};
	allCase[1].push_back("1");
	queue<int> q;
	q.push(1);
	while (!q.empty()){
		int curNum = q.front();
		int nextNum = curNum + 1;
		q.pop();
		if (nextNum <= 9){
			for (int i = 0; i < allCase[curNum].size(); i++) {
				string curString = allCase[curNum][i];
				for (int j = 0; j < operatorChar.size(); j++) {
					string nextString = curString + operatorChar[j] + to_string(nextNum);
					allCase[nextNum].push_back(nextString);
//					cout << "made string "  + nextString + "\n";
				}
				//string 
			}
			q.push(nextNum);
		}
	}
	for (int t_i = 0; t_i < T; t_i++) {
		int num;
		cin >> num;
		for (int i = 0; i < allCase[num].size(); i++) {
			calculate(allCase[num][i]);
		}
		sort(sol[num].begin(), sol[num].end());
		for (int i = 0; i < sol[num].size(); i++) {
			cout << sol[num][i] + "\n";
		}
		if (t_i != T - 1)
			cout << "\n";
	}
	return (0);
}

