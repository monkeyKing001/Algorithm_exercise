#include <tuple>
#include <utility>
#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;
char maps[1001][1001];
char f_visited[1001][1001];
char j_visited[1001][1001];
int j_step = INT_MAX;
int f_step = INT_MIN;
pair <int, int> j_start;
pair <int, int> f_start;
int r, c;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
stack <tuple <int, int, int>> s;
queue <tuple <int, int, int>> q;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
	{
		string input;
		cin >> input;
		for (int j = 0; j < c; ++j)
		{
			maps[i][j] = input[j];
			if (input[j] == 'J')
			{
				j_start.first = i;
				j_start.second = j;
			}
			else if (input[j] == 'F')
			{
				f_start.first = i;
				f_start.second = j;
			}
		}
	}
	//test out
	for (int i = 0; i < r; ++i)
	{
		string input;
		cin >> input;
		for (int j = 0; j < c; ++j)
			cout << maps[i][j];
		cout << "\n";
	}
	//bfs queue fire
	f_step = 1;
	q.push(make_tuple(f_start.first, f_start.second, f_step));
	while (!q.empty())
	{
		int current_r, current_c, current_step;
		current_r = get<0>(q.front());
		current_c = get<1>(q.front());
		current_step = get<2>(q.front());
		q.pop();
		f_visited[current_r][current_c] = current_step;
		for (int i = 0; i < 4; ++i)
		{
			int next_r = current_r + dr[i];
			int next_c = current_c + dc[i];
			if (next_r > -1 && next_r < r && next_c > -1 && next_c < c)
			{
				if ((maps[next_r][next_c] == '.' || maps[next_r][next_c] == 'J') 
						&& !f_visited[next_r][next_c])
					q.push(make_tuple(next_r, next_c, current_step + 1));
			}
		}
	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
			cout << (int)f_visited[i][j];
		cout << "\n";
	}
	
	//dfs stack jun

	return (0);
}

