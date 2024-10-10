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

vector<int> p;

int find_(int u){
	if (p[u] == -1)
		return (u);
	p[u] = find_(p[u]);
	return (p[u]);
}

void union_(int u, int v){
	int p_u = find_(u);
	int p_v = find_(v);
	if (p_u == p_v)
		return;
	if (p_u > p_v){
		int temp = p_u;
		p_u = p_v;
		p_v = temp;
	}
	p[p_v] = p_u;
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	p.resize(n + 1, -1);
	vector<vector<int>> info(m, vector<int>(3, 0));
	int count = 0;
	int sol = 0;
	for (int i = 0; i < m; i++) 
		cin >> info[i][1] >> info[i][2] >> info[i][0];
	sort(info.begin(), info.end());
	for (int i = 0; i < m && count != n - 1; i++) {
		int cost = info[i][0];
		int u = info[i][1];
		int v = info[i][2];
		if (find_(u) != find_(v)){
			count++;
			sol += cost;
			union_(u, v);
//			cout << "from u, v, cost : "<< u << ", "<< v << ", " << cost << "\n";
//			cout << "p_u, p_v, cost : "<< find_(u) << ", "<< find_(v) << "\n";
		}
	}
	cout << sol; 
	return (0);
}

