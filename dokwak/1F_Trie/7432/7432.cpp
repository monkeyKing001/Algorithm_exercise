#include <queue>
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

class TRIE{

	public:
	string dir_name_;
	map<string, TRIE *> children_;
	TRIE(const string &dir_name) : dir_name_(dir_name){}
	void insert(const string& dir){
		if (children_.find(dir) == children_.end()){
			TRIE *child = new TRIE(dir);
			this -> children_[dir] = child;
			this -> children_.insert({dir, child});
		}
	}
};

TRIE *root = new TRIE("");

vector<string> split(const string &full_dir){
	stringstream ss(full_dir);
	vector<string> buf;
	string tok;
	char del = '\\';
	while (getline(ss, tok, del)){
		buf.push_back(tok);
	}
	return (buf);
}

void insert(const string &full_dir){
	vector<string> tokens = split(full_dir);
	TRIE *cur = root;
	for (int i = 0; i < tokens.size(); i++) {
		string dir = tokens[i];
		cur -> insert(dir);
		cur = cur->children_[dir];
	}
}

void print(TRIE *trie, int depth){
	map<string, TRIE *>::iterator it = trie->children_.begin();
	for (int i = 0; i < depth - 1; i++) {
		cout << " ";
	}
	if (trie->dir_name_.size() != 0)
		cout << trie->dir_name_ << "\n";
	while(it != trie->children_.end()){
		print(it->second, depth + 1);
		it++;
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string full_dir;
		cin >> full_dir;
		insert(full_dir);
	}
	print(root, 0);
	return (0);
}

