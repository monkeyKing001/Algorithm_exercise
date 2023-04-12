#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>

using namespace std;
int n;
vector <vector<int> >cost_per_house;
int house_cost[1000][3];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		vector <int> temp(3);
		int r,g,b;
		cin >> r >> g >> b;
		temp[0] = r;
		temp[1] = g;
		temp[2] = b;
		cost_per_house.push_back(temp);
	}
	//pair.first = color;(0 -> r, 1 -> g, 2 -> b)
	//pair.second = cost;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			house_cost[i][0] = cost_per_house[i][0];
			house_cost[i][1] = cost_per_house[i][1];
			house_cost[i][2] = cost_per_house[i][2];
		}
		else {
			house_cost[i][0] = cost_per_house[i][0] + 
				min(house_cost[i - 1][1], house_cost[i - 1][2]);
			house_cost[i][1] = cost_per_house[i][1] + 
				min(house_cost[i - 1][0], house_cost[i - 1][2]);
			house_cost[i][2] = cost_per_house[i][2] + 
				min(house_cost[i - 1][0], house_cost[i - 1][1]);
		}
	}
	int sol = INT_MAX;
	for (int i = 0; i < 3; i++)
	{
		if (sol > house_cost[n - 1][i])
			sol = house_cost[n - 1][i];
	}
	cout << sol;
	return (0);
}
