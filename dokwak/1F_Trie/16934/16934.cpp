#include <random>
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

map<string, string> nickname_prefix_table;
map<string, int> nickname_count;

class TRIE {
	public:
		char char_;
		int h_;
		map<char, TRIE*> children_;
	
	TRIE(char char__, int h__) : char_(char__), h_(h__) {}
	
	void insert(char char__){
		if (children_.find(char__) == children_.end()) {
			TRIE *child = new TRIE(char__, h_ + 1);
			children_.insert({char__, child});
		}
	}

	void insert_str(const string& s){
		TRIE *cur = this;
		for (int i = 0; i < s.size(); i++) {
			char char__ = s[i];
			cur -> insert(char__);
			cur = cur -> children_[char__];
		}
	}
};

TRIE *root = new TRIE('0', 0);

TRIE *find_last_prefix(string str) {
	TRIE *cur = root;
	int i = -1;
	while (++i < str.size()){
		char chr = str[i];
		if (cur -> children_.find(chr) == cur -> children_.end())
			break;
		cur = cur -> children_[chr];
	}
	return cur;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		string postfix = "";
		cin >> str;
		TRIE *last_prefix = find_last_prefix(str);
		string new_prefix = "";
		//no available prefix
		if (last_prefix -> h_ == str.size()) {
			if (nickname_count[str] != 0)
				postfix = to_string(nickname_count[str] + 1);
			new_prefix = str + postfix;
		}
		else {
			new_prefix = str.substr(0, last_prefix->h_ + 1);
		}
		nickname_prefix_table[str] = new_prefix;
		root -> insert_str(str);
		nickname_count[str]++;
		cout << nickname_prefix_table[str] << "\n";
	}
	return (0);
}

