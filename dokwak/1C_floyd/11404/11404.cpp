#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <iterator>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int n, m;
long long v1, v2, cost;
long long total_cost[200][200];
#define MAX 100000000

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++) {
				total_cost[i+1][j+1] = MAX;
		}
	}
	for (int i = 0; i < m; ++i) {
		cin >> v1 >> v2 >> cost;
		total_cost[v1][v2] = min(total_cost[v1][v2], cost);
	}
	for (int i = 0; i < n; ++i) {
		int bridge = i + 1;
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				total_cost[j+1][k+1] = min(total_cost[j+1][k+1], total_cost[j+1][bridge] + total_cost[bridge][k+1]);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (total_cost[i+1][j+1] != MAX && i != j)	
				cout << total_cost[i+1][j+1] << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
	return (0);
}

