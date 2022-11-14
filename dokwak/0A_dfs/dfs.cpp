#include <bits/stdc++.h>
using namespace std;
# define row first
# define col second
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dcol[4] = {1,0,-1,0};
int drow[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미
int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	pair <int, int> start = make_pair(0, 0);
	stack <pair <int, int> > find_next_trav;

	vis[start.row][start.col] = 1;
	find_next_trav.push(start);
	while (!find_next_trav.empty())
	{
		pair <int ,int> cur = find_next_trav.top();
		pair <int ,int> next = find_next_trav.top();
		cout << '(' << cur.row << ", " << cur.col << ") -> ";
		find_next_trav.pop();
		for (int i = 0; i < 4; i++)
		{
			int	next_row = next.row + drow[i];
			int	next_col = next.col + dcol[i];
			if (next_row < 0 || next_row >= n || next_col < 0 || next_col >= m)
				continue ;
			if (vis[next_row][next_col] || board[next_row][next_col] == 0)
				continue ;
			vis[next_row][next_col] = 1;
			find_next_trav.push(make_pair(next_row, next_col));
		}
	}
	return (0);
}

