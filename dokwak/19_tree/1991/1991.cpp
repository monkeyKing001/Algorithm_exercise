#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;

int n;
int no = '.' - 'A';
vector<vector<int>> g(26, vector<int>(2, -1));
void pre(int cur){
	//me left right
	cout << (char)(cur + 'A'); 
	if (g[cur][0] != no){
		int left = g[cur][0];
		pre(left);
	}
	if (g[cur][1] != no){
		int right = g[cur][1];
		pre(right);
	}
}

void post(int cur){
	//left right me
	if (g[cur][0] != no){
		int left = g[cur][0];
		post(left);
	}
	if (g[cur][1] != no){
		int right = g[cur][1];
		post(right);
	}
	cout << (char)(cur + 'A'); 
}

void inOrd(int cur){
	//left me right
	if (g[cur][0] != no){
		int left = g[cur][0];
		inOrd(left);
	}
	cout << (char)(cur + 'A'); 
	if (g[cur][1] != no){
		int right = g[cur][1];
		inOrd(right);
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char char1, char2, char3;
		cin >> char1 >> char2 >> char3;
		int pos1, pos2, pos3;
		pos1 = char1 - 'A';
		pos2 = char2 - 'A';
		pos3 = char3 - 'A';
		int parent = pos1;
		int left = pos2;
		int right = pos3;
		g[parent][0] = left;
		g[parent][1] = right;
	}
	pre(0);
	cout << "\n";
	inOrd(0);
	cout << "\n";
	post(0);
	return (0);
}
