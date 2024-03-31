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
string vowel = "aeiou";
bool isVowel(char chr){
	if (vowel.find(chr) != string::npos)
		return true;
	return false;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> str;
	while (str != "end"){
		bool acceptable = false;
		//acceptable check
		//vowel check
		for (int i = 0; i < vowel.length() && !acceptable; i++){
			if (str.find((char)vowel[i]) != string::npos)
				acceptable = true;
		}
		//same two chars in row
		for (int i = 0; i < str.length() && acceptable; i++) {
			char curChar = str[i];
			bool curCharIsVowel = isVowel(curChar);
			if (i != str.length() - 1) {
				int j = i + 1;
				char nextChar = str[j];
				bool nextCharIsVowel = isVowel(nextChar);
				//same two chars in row but they are not e nor o
				if (curChar == nextChar) {
					if (curChar != 'e' && curChar != 'o')
						acceptable = false;
				}
				//same three vowel flag in row
				if (acceptable && curCharIsVowel == nextCharIsVowel) {
					if (j != str.length() - 1 && curCharIsVowel == isVowel(str[j + 1]))
						acceptable = false;
				}
			}
		}
		cout << "<" << str << "> is"; 
		if (!acceptable)
			cout << " not";
		cout << " acceptable.\n";
		cin >> str;
	}
	return (0);
}

