#ifndef Node_HPP
#define Node_HPP
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int n, m;
string del = "--";

class Node
{

	private:
		int _h;
		string _str;
		vector<Node *> _child;
		

	public:
		Node(void);
		Node(const Node& obj);
		Node& operator = (const Node& obj);
		~Node(void);
		Node(string str, int h) { _h = h; _str = str; }
		const int &getH(void) const { return _h; }
		const string& getStr(void) const { return _str; }
		Node& getChild(int idx) const { return *(_child[idx]); }
		const int findChild(string key){
			for (int i = 0; i < _child.size(); i++) {
				if (_child[i]->getStr() == key)
					return i;
			}
			return (-1);
		}
		vector<Node*> &getChildVec(void) { return _child; }
};

bool cmp(Node *node1, Node *node2){
	return (node1 -> getStr() < node2 -> getStr());
}


void dfs(Node *node){
	for (int i = 0; i < node -> getH(); i++) {
		cout << del;
	}
	cout << node ->getStr() + "\n";
	vector<Node *> childs = node ->getChildVec();
	sort(childs.begin(), childs.end() ,cmp);
	for (int i = 0; i < childs.size(); i++) {
		dfs(childs[i]);
	}
}

int	main(int argc, char **argv) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	Node *root = new Node("root", -1);
	for (int i = 0; i < n; i++) {
		int level;
		Node *cur = root;
		cin >> level;
		for (int j = 0; j < level; j++) {
			string strInput = "";
			cin >> strInput;
			int childIdx = cur -> findChild(strInput);
			// cannot find child
			if (childIdx == -1){
				Node *newNode = new Node(strInput, cur -> getH() + 1);
				vector<Node*> &curChild = cur -> getChildVec();
				curChild.push_back(newNode);
				cur = newNode;
			}
			else{
				cur = &(cur -> getChild(childIdx));
			}
		}
	}
	vector<Node *> childs = root ->getChildVec();
	sort(childs.begin(), childs.end() ,cmp);
	for (int i = 0; i < childs.size(); i++) {
		dfs(childs[i]);
	}
	return (0);
}
#endif /* 14725_HPP */
