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
string del = "--";


class Node{

	public:
		int h;
		string str;
		vector<Node *> child;
		Node();
		Node(string str, int h){
			this -> str = str;
			this -> h = h;
		}
		int find(string key){
			for (int i = 0; i < child.size(); i++) {
				if (child[i] -> str == key)
					return i;
			}
			return -1;
		}
		Node *getChild(int i){
			return (this -> child[i]);
		}
};

bool cmp(Node *n1, Node *n2){
	return (n1 -> str < n2 -> str);
}

void dfs(Node *node){
	int cur_h = node -> h;
	sort(node -> child.begin(), node -> child.end(), cmp);
	for (int i = 0; i < cur_h; i++) {
		cout << del;
	}
	cout << node -> str;
	cout << "\n";
	for (int i = 0; i < node -> child.size(); i++) {
		dfs(node -> child[i]);
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	Node *root = new Node("root", 0);
	for (int i = 0; i < n; i++) {
		int count;
		cin >> count;
		Node *cur = root;
		for (int j = 0; j < count; j++) {
			string str;
			cin >> str;
			int childIdx = cur -> find(str);
			if (childIdx == -1) {
				Node *newChild = new Node(str, j);
				cur -> child.push_back(newChild);
				cur = newChild;
			}
			else {
				cur = cur -> child[childIdx];
			}
		}
	}
	sort(root -> child.begin(), root -> child.end(), cmp);
	for (int i = 0; i < root -> child.size(); i++) {
		dfs(root -> child[i]);
	}
	return (0);
}
