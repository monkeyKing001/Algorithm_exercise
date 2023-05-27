#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

#define MAX 987654321

using namespace std;
int n, m;
int dist[11][11];
int dp[11][1 << 11];
int pat[11];

int TSP(int cur, int visited_bits)
{
	if (visited_bits == (1 << n) - 1)
	{
		if (dist[cur][0] == 0)
			return (MAX);
		return (dist[cur][0]);
	}
//	cout << cur << " is cur\n";
	int &cur_cost = dp[cur][visited_bits];
	if (cur_cost != -1)//visited
		return (cur_cost);
	cur_cost = MAX;
	for (int i = 0; i < n; i++)
	{
		int next_check = 1 << i;
//		cout << "next checking : " << next_check << "\n";
		if ((visited_bits & next_check) != 0)//already viisted
			continue;
		if (dist[cur][i] == 0)//no way
			continue;
//		cout << "going from, to : " << cur << ", " << i << "\n";
		cur_cost = min(cur_cost, TSP(i, visited_bits | next_check) + dist[cur][i]);
//		cout << "after travel, from, next, bits_visited, cost is " << cur << ", " 
//			<< i << ", " << visited_bits << ", " << cur_cost << "\n";
	}
	return (cur_cost);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> dist[i][j];
	memset(dp, -1, sizeof(dp));
	cout << TSP(0, 1);
	return (0);
}
