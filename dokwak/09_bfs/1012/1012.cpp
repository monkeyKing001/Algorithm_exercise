#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int field[51][51];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, n, m, k;
	queue <pair <int, int>> q;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}
		int worm = 0;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (field[y][x] == 1)
				{
					//bfs start
					worm++;
					pair<int ,int> start = make_pair(y, x);
					field[y][x] = 0;
					q.push(start);
//					cout << "start x, y : " << x << ", " << y << "\n";
					while (!q.empty())
					{
						int c_y = q.front().first;
						int c_x = q.front().second;
						q.pop();
						for (int i = 0; i < 4; i++)
						{
							int n_y = c_y + dy[i];
							int n_x = c_x + dx[i];
							if (n_y >= 0 && n_y < n &&
									n_x >= 0 && n_x < m &&
									field[n_y][n_x] == 1)
							{
//								cout << "pushing n_x, n_y : " << n_x << ", " << n_y << "\n";
								q.push(make_pair(n_y, n_x));
								field[n_y][n_x] = 0;
							}
						}
					}
				}
			}
		}
		cout << worm << "\n";
	}
	return (0);
}

