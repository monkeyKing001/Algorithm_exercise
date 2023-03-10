#include <bits/stdc++.h>
using namespace std;

int m, n;
int c, r;
int box[1001][1001];
queue <pair <int, int>> q;
int unrip;
int max_step = 0;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	c = m;
	r = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 0)
				unrip++;
			else if (box[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}
	while(q.size())
	{
		int c_r;
		int c_c;
		int c_step;
		c_r = q.front().first;
		c_c = q.front().second;
		c_step = box[c_r][c_c];
		if (max_step < c_step)
			max_step = c_step;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int n_r = c_r + dr[i];
			int n_c = c_c + dc[i];
			int n_step = c_step + 1;
			if (n_r > -1 && n_r < r && n_c > -1 && n_c < c && !box[n_r][n_c])
			{
				q.push(make_pair(n_r, n_c));
				box[n_r][n_c] = n_step;
				unrip--;
			}
		}
	}
	if (unrip)
	{
		cout << -1;
		return (0);
	}
	cout << max_step - 1;
	return (0);
}
