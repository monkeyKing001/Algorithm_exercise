#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int dr[8] = {2, 2, -1, 1, -2, -2, -1, 1};
int dc[8] = {1, -1, -2, -2, -1, 1, 2, 2};
int board[301][301];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, size;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				board[i][j] = 0;
		}
		int start_r, start_c;
		int target_r, target_c;
		cin >> start_r >> start_c >> target_r >> target_c;
		board[start_r][start_c] = 1;
		queue <pair <int, int> > q;
		q.push(make_pair(start_r, start_c));
		while (q.size())
		{
			int c_r = q.front().first;
			int c_c = q.front().second;
			int c_step = board[c_r][c_c];
			q.pop();
			if (c_r == target_r && c_c == target_c)
			{
				cout << c_step - 1 << "\n";
				break ;
			}
			for (int i = 0; i < 8; i++)
			{
				int n_r = c_r + dr[i]; 
				int n_c = c_c + dc[i]; 
				if (n_r > -1 && n_r < size && n_c > -1 && n_c < size && !board[n_r][n_c])
				{
					board[n_r][n_c] = c_step + 1;
					q.push(make_pair(n_r, n_c));
				}
			}
		}
	}
	return (0);
}

