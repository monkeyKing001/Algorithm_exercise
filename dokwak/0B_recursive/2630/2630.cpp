#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int sol;
int paper[129][129];
int dr[2] = {0, 1};
int dc[2] = {1, 0};
int n;
int w;
int b;
void rec(int start_r, int start_c, int size)
{
	queue <pair <int, int>> q;
	int c_col = paper[start_r][start_c];
	int perfect = 1;
	int visited[129][129];
	for (int i = start_r; i < size + start_r; i++)
	{
		for (int j = start_c; j < size + start_c; j++)
		{
			visited[i][j] = 0;
		}
	}
	visited[start_r][start_c] = 1;
	q.push(make_pair(start_r, start_c));
	while (q.size() && perfect)
	{
		int c_r = q.front().first;
		int c_c = q.front().second;
		q.pop();
		for (int i = 0; i < 2; i++)
		{
			int n_r = c_r + dr[i];
			int n_c = c_c + dc[i];
			if (n_r < start_r + size && n_r < n &&
					n_c < start_c + size && n_c < n && !visited[n_r][n_c])
			{
				if (paper[n_r][n_c] == c_col)
				{
					q.push(make_pair(n_r, n_c));
					visited[n_r][n_c] = 1;
				}
				else
				{	
					int n_size = size / 2;
					rec(start_r, start_c, n_size);
					rec(start_r + n_size, start_c, n_size);
					rec(start_r + n_size, start_c + n_size, n_size);
					rec(start_r, start_c + n_size, n_size);
					perfect = false;
					break;
				}
			}
		}
	}
	if (perfect)
	{
		if (c_col == 1)
			b++;
		else
			w++;
	}
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int color;
			cin >> color;
			paper[i][j] = color;
		}
	}
	rec(0, 0, n);
	cout << w << "\n" << b;
	return (0);
}
