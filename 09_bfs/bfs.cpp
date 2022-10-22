#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

//1 is blue, 0 is red.
//blue should be visited
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
//pushing cords in the queue means searching next node to visit from that cord not visiting that cord
//poping cords means finished the visiting
int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int,int> > Q;
	pair<int, int> start = make_pair(0, 0);
	vis[0][0] = 1;
	Q.push(start);

	//bfs start
	while (!Q.empty())
	{
		pair <int, int> current = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int	next_X = current.X + dx[dir];
			int	next_Y = current.Y + dy[dir];
			if (next_X < 0 || next_X >= n || next_Y < 0 || next_Y >= m)
				continue ;
			if (vis[next_X][next_Y] || board[next_X][next_Y] != 0)
				continue ;
			vis[next_X][next_Y] = 1;
			pair <int , int> next = make_pair(next_X, next_Y);
			Q.push(next);
		}
	}
	return (0);
}
