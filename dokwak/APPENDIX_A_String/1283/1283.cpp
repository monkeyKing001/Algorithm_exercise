#include <ios>
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

	//way 1. cin just n
//	cin >> n;
	
	//way 2. cin with cin.ignore()
//	cin >> n;
//	cin.ignore();

	//way 3. getline wo delimeter and with cin.ignore()  -> wrong way
//	getline(cin, input);
//	cin.ignore();
//	n = stoi(input);

	//way 4. getline wo delimeter and cin.ignore() -> right way
	getline(cin, input);
	n = stoi(input);

	set<char> shortCut;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str, '\n');
//		cout << "str : " + str + "\n";
		v.push_back(str);
	}
	for (int i = 0; i < n; i++) {
		string str = v[i];
		vector<string> tokens;
		stringstream ss(str);
		string temp;
		while (getline(ss, temp, ' '))
			tokens.push_back(temp);
		bool found = false;
		for (int t_i = 0; t_i < tokens.size(); t_i++) {
			char initial = tokens[t_i][0];
			if (shortCut.find(tolower(initial)) == shortCut.end()){
				//found shortCut 
				string repl = "[";
				repl += initial;
				repl += "]";
				tokens[t_i].replace(tokens[t_i].find(initial), sizeof(initial), repl);
				found = true;
				shortCut.insert(tolower(initial));
				break;
			}
		}
		if (!found){
			for (int t_i = 0; t_i < tokens.size() && !found; t_i++) {
				for (int chr_i = 0; chr_i < tokens[t_i].length(); chr_i++) {
					char target = tokens[t_i][chr_i];
					if (target != ' ' && shortCut.find(tolower(target)) == shortCut.end()){
						string repl = "[";
						repl += target;
						repl += "]";
						tokens[t_i].replace(chr_i, sizeof(target), repl);
						shortCut.insert(tolower(target));
						found = true;
						break;
					}
				}
			}
		}
		v[i] = "";
		for (int t_i = 0; t_i < tokens.size(); t_i++) {
			v[i] += tokens[t_i];
			if (t_i != tokens.size() - 1)
				v[i] += " ";
		}
		cout << v[i] << "\n";
	}
	return (0);
}

