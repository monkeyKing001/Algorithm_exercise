#include <bits/stdc++.h>
using namespace std;
#define row first
#define col second
int	board[501][501];
int	visited[501][501] = {0, };
int	drow[4] = {1, 0, -1, 0};
int	dcol[4] = {0, 1, 0, -1};
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	n, m;
	int	pic_num = 0;
	int	pic_size = 0;
	queue <pair <int, int> > Q;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	//bfs from every point
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int start_row = i;
			int start_col = j;
			//check current coordinates can be a start point
			if (!board[start_row][start_col] || visited[start_row][start_col])
				continue ;
			//bfs start
			pair <int , int> start = make_pair(start_row, start_col);
			//mark the start coordinate as visitied
			visited[start_row][start_col] = 1;
			//push the current coordinate in queue(scheduling for searching next coordinate starting from queue.front())
			Q.push(start);
			int	pic_size_temp = 1;
			//pic num + 1
			pic_num++;
			while(!Q.empty())
			{
				//remove the current coordinate from the queue
				pair <int, int> current = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++)
				{
					int next_row, next_col;
					next_row = current.row + drow[dir];
					next_col = current.col + dcol[dir];
					if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m)
						continue ;
					if (visited[next_row][next_col] || board[next_row][next_col] == 0)
						continue ;
					//mark the next coordinate as visited
					visited[next_row][next_col] = 1;
					//push the next coordinate in the queue(scheduling for searching next coordinate starting from queue.front())
					Q.push(make_pair(next_row, next_col));
					//pic_size plus
					pic_size_temp++;
				}
			}
			//update max pic size
			pic_size = max(pic_size, pic_size_temp);
		}
	}
	cout << pic_num << "\n" << pic_size;
	return (0);
}
