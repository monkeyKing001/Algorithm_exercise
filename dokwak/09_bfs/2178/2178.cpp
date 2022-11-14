#include <bits/stdc++.h>
using namespace std;
# define row first
# define col second
int	drow[4] = {1, 0, -1, 0};
int	dcol[4] = {0, 1, 0, -1};

int	main(int argc, char **argv)
{
	int	n, m;
	int	min_mov = 0;
	queue <pair <int, int> > Q;
	string map[101];
	int distance[101][101] = {0, };
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> map[i];
	distance[0][0] = 1;
	Q.push(make_pair(0, 0));
	//bfs
	while (!Q.empty())
	{
		pair <int, int> current = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int next_row = current.row + drow[dir];
			int next_col = current.col + dcol[dir];
			if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m)
				continue ;
			//4th try : fixed dis[n_rw][n_cl] < dis[cur.row][cur.col] + 1 to <=
			//same distance -> no visiting
			if (map[next_row][next_col] == '0' || (distance[next_row][next_col] && distance[next_col][next_row] <= distance[current.row][current.col]  + 1))
				continue ;
			if (distance[next_row][next_col] == 0)
				distance[next_row][next_col] = distance[current.row][current.col] + 1;
			else
			{
				distance[next_row][next_col] = 
					min(distance[next_col][next_row], distance[current.row][current.col] + 1);
			}
			Q.push(make_pair(next_row, next_col));
		}
	}
	printf("%d", distance[n-1][m-1]);
	return (0);
}

