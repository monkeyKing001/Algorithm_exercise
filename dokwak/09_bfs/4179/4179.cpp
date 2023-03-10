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
int j_step = INT_MAX;
pair <int, int> j_start;
vector <pair <int, int>> f_start;
int r, c;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int maps[1001][1001];
int f_visited[1001][1001];
int j_visited[1001][1001];
queue <pair <int, int>> q;
//queue <pair <int, int>> q;

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
				q.push(make_pair(i, j));
				f_visited[i][j] = 1;
			}
		}
	}
	//bfs queue fire
	while (!q.empty())
	{
		int current_r, current_c, current_step;
		current_r = q.front().first;
		current_c = q.front().second;
		current_step = f_visited[current_r][current_c];
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int next_r = current_r + dr[i];
			int next_c = current_c + dc[i];
			int next_step = current_step + 1;
			if (next_r > -1 && next_r < r && next_c > -1 && next_c < c)
			{
				if ((maps[next_r][next_c] == '.' || maps[next_r][next_c] == 'J') 
						&& (!f_visited[next_r][next_c]))
					{
						f_visited[next_r][next_c] = next_step;
						q.push(make_pair(next_r, next_c));
					}

			}
		}
	}
	//bfs stack jun
	j_visited[j_start.first][j_start.second] = 1;
	q.push(make_pair(j_start.first, j_start.second));
	while (!q.empty())
	{
		int current_r, current_c, current_step;
		current_r = q.front().first;
		current_c = q.front().second;
		current_step = j_visited[current_r][current_c];
		q.pop();
		if ((current_r == 0 || current_r == r - 1 || current_c == c - 1 || current_c == 0) && (j_step > current_step))
			j_step = current_step;
		for (int i = 0; i < 4; ++i)
		{
			int next_r = current_r + dr[i];
			int next_c = current_c + dc[i];
			int next_step = j_visited[current_r][current_c] + 1;
			if (next_r > -1 && next_r < r && next_c > -1 && next_c < c)
			{
				if ((maps[next_r][next_c] == '.') 
						&& !j_visited[next_r][next_c] && (!f_visited[next_r][next_c] || f_visited[next_r][next_c] > next_step))
				{
					q.push(make_pair(next_r, next_c));
					j_visited[next_r][next_c] = next_step;
				}
			}
		}
	}
	if (j_step != INT_MAX)
		cout << j_step;
	else
		cout << "IMPOSSIBLE";
	return (0);
}

