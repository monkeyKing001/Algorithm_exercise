#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <queue>

using namespace std;
int n, m;
queue <int> z_idg;
vector <int> adj_list[32100];
int indeg[32100];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		adj_list[a].push_back(b);
		indeg[b]++;
	}
	//find the first indeg 0
	for (int i = 1; i < n + 1; ++i) {
		if (indeg[i] == 0)
		{
//			cout << i << " is zero degree\n";
			z_idg.push(i);
		}
	}
	while (!z_idg.empty())
	{
		int sorted = z_idg.front();
		z_idg.pop();
		cout << sorted << " ";
		for (int i = 0; i < adj_list[sorted].size(); ++i) {
			indeg[adj_list[sorted][i]]--;
			if (indeg[adj_list[sorted][i]] == 0)
				z_idg.push(adj_list[sorted][i]);
		}
	}
	return (0);
}

