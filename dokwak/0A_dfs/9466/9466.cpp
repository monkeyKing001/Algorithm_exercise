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
vector<int> g;
vector<int> cycle_starter;
vector<bool> visited;
set<int> cycle_member;

char buf[1 << 17];

inline char read()
{
	static int idx = 1 << 17;
	if (idx == 1 << 17)
	{
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}

inline int readInt()
{
	int sum = 0;
	char now = read();

	while (now == 10 || now == 32) now = read();
	while (now >= 48 && now <= 57)
	{
		sum = sum * 10 + now - 48;
		now = read();
	}

	return sum;
}

int find_p(int u){
	if (p[u] == -1)
		return u;
	p[u] = find_p(p[u]);
	return (p[u]);
}

void union_uv(int u, int v){
	int p_u = find_p(u);
	int p_v = find_p(v);
	if (p_v < p_u){
		int temp = p_u;
		p_u = p_v;
		p_v = temp;
	}
	p[p_v] = p_u;
}

bool cycle_rec(int cur){
	visited[cur] = true;
	int next = g[cur];
	if (visited[next]){
		cycle_member.insert(cur);
	}
	else{
		if (cycle_rec(next))
			cycle_member.insert(cur);
	}
	visited[cur] = false;
	return (cycle_member.find(cur) != cycle_member.end());
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = readInt();
	for (int t_i = 0; t_i < T; t_i++) {
		n = readInt();
		cycle_starter.clear();
		g.reserve(n + 1);
		p.reserve(n + 1);
		g.assign(n + 1, 0);
		p.assign(n + 1, -1);
		//make graph and find cycle_starter;
		for (int u = 1; u < n + 1; u++) {
			int v = readInt();
			g[u] = v;
			if (find_p(u) == find_p(v))
				cycle_starter.push_back(u);
			else
				union_uv(u, v);
		}
		//count members
		int ans = n;
		for (int start_i = 0; start_i < cycle_starter.size(); start_i++) {
			int start = cycle_starter[start_i];
			visited.reserve(n + 1);
			visited.assign(n + 1, false);
			cycle_member.clear();
			cycle_rec(start);
			ans -= cycle_member.size();
//			cout << "\ncycle_start, member size : " << start << ", " << cycle_member.size();
		}
		cout << ans << "\n";
	}
	return (0);
}

