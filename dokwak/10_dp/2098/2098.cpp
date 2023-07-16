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
int dp[17][(2 << 16)];
int dist[17][17];

int TSP(int cur, int bits_visited) //bits_visited -> 0 ~ 2^n;
{
	if (bits_visited == (1 << n) - 1)
	{
//		cout << "traveling from "<< cur <<" has end.\n";
//		cout << "cost : " << dist[cur][0] << "\n";
		if (dist[cur][0] == 0)
			return MAX;
		return dist[cur][0]; //base case; 
	}
	int &cur_cost = dp[cur][bits_visited];
	if (cur_cost != -1)//if visited, return visited cost
	{
//		cout << cur <<" has been visited. the cost is " << cur_cost << "\n";
		return cur_cost;
	}
	//dp start
	cur_cost = MAX;
	for (int next = 0; next < n; next++)
	{
		//1st fixt
		if ((bits_visited & (1 << next)) == (1 << next))//according to bits_visited, next has been visited?
			continue ;//then continue;
		if (dist[cur][next] == 0)//next has not visited but no path btw cur and next 
			continue ;//then continue;
//		cout << "going from, to : " << cur << ", " << next << "\n";
		cur_cost = min(cur_cost, TSP(next, bits_visited | (1 << next)) + dist[cur][next]);
//		cout << "after travel, from, next, bits_visited, cost is " << cur << ", " 
//			<< next << ", " << bits_visited << ", " << cur_cost << "\n";
		//next hasn't visited and has path btw cur - next
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
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
//			cout << dist[i][j] << " ";
		}
	}
	memset(dp, -1 ,sizeof(dp));
	cout << TSP(0, 1) << "\n";
	return (0);
}

