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
	int ingredient_count;
	cin >> ingredient_count;
	vector<vector<int>> g(n, vector<int> (n, 0));
	vector<int> indegree(n, 0);
	vector<int> outdegree(n, 0);
	for (int i = 0; i < ingredient_count; i++) {
		int u, v;
		cin >> u >> v;
	}
	//if some point has no indegree, it is startPoint
	int startPoint = -1;
	int targetPoint = -1;
	return (0);
}

