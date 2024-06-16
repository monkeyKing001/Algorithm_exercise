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

bool cppStyle = false;
bool javaStyle = false;
bool error = false;

set <char> s;
string cppToJava(string input, string &buf){
	int i = 0;
	if (input[0] == '_')
		error = true;
	while (i != input.size() && !error){
		if (input[i] >= 'A' && input[i] <= 'Z'){
			error = true;
			break;
		}
		if (input[i] == '_'){
			if (i == input.size() - 1 || !(input[i + 1] >= 'a' && input[i + 1] <= 'z')){
				error = true;
				break;
			}
			i++;
			buf.push_back(toupper(input[i]));
		}
		else
			buf.push_back(input[i]);
		i++;
	}
	if (error)
		buf = "Error!";
	return (buf);
}

string javaToCpp(string input, string &buf){
	int i = 0;
	if (input[0] >= 'A' && input[0] <= 'Z')
		error = true;
	//double check
	while (i != input.size() && !error){
		if (input[i] >= 'A' && input[i] <= 'Z')//uppper to lower
			buf.push_back('_');
		buf.push_back(tolower(input[i]));
		i++;
	}
	if (error)
		buf = "Error!";
	return (buf);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string input;
	string buf;
	cin >> input;
	//cpp or java?
	for (int i = 0; i < input.size(); i++) {
		s.insert(input[i]);
	}
	set<char>::iterator it = s.begin();
	if (s.find('_') != s.end())
		cppToJava(input, buf);
	else
		javaToCpp(input, buf);
	cout << buf;
	return (0);
}

