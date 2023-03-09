#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
string pic[101];
int visited[101][101];
int visited2[101][101];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};
queue< pair <int, int>> q;
int n;
int area;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pic[i];
	//normal
	for (int i = 0; i < n; i++)
	{
		int r = i;
		for (int j = 0; j < n; j++)
		{
			int c = j;
			if (!visited[r][c])
			{
				char color = pic[r][c];
				q.push(make_pair(r, c));
				visited[r][c] = 1;
				area++;
				if (pic[r][c] == 'G')
					pic[r][c] = 'R';
				while (q.size())
				{
					int current_r = q.front().first;
					int current_c = q.front().second;
					q.pop();
//					cout << "target_color, current_r, cuurent_c, current_color : "
//						<< color 
//						<< ", "
//						<< current_r
//						<< ", "
//						<< current_c
//						<< ", "
//						<< pic[current_r][current_c] << "\n";
					for (int k = 0; k < 4; k++)
					{
						int next_r = current_r + dr[k];
						int next_c = current_c + dc[k];
						if (next_r > -1 && next_r < n && next_c > -1 && next_c < n && !visited[next_r][next_c] && pic[next_r][next_c] == color)
						{
//							cout << "target_color, next_r, next_c, next_color : "
//								<< color 
//								<< ", "
//								<< next_r
//								<< ", "
//								<< next_c
//								<< ", "
//								<< pic[next_r][next_c] << "\n";
							q.push(make_pair(next_r, next_c));
							visited[next_r][next_c] = 1;
							if (pic[next_r][next_c] == 'G')
								pic[next_r][next_c] = 'R';
						}
					}
				}
			}
		}
	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << pic[i][j];
//		}
//		cout << "\n";
//	}
	cout << area << " ";
	area = 0;
	for (int i = 0; i < n; i++)
	{
		int r = i;
		for (int j = 0; j < n; j++)
		{
			int c = j;
			if (!visited2[r][c])
			{
				char color = pic[r][c];
				q.push(make_pair(r, c));
				visited2[r][c] = 1;
				area++;
				while (q.size())
				{
					int current_r = q.front().first;
					int current_c = q.front().second;
					q.pop();
//					cout << "target_color, current_r, cuurent_c, current_color : "
//						<< color 
//						<< ", "
//						<< current_r
//						<< ", "
//						<< current_c
//						<< ", "
//						<< pic[current_r][current_c] << "\n";
					for (int k = 0; k < 4; k++)
					{
						int next_r = current_r + dr[k];
						int next_c = current_c + dc[k];
						if (next_r > -1 && next_r < n && next_c > -1 && next_c < n && !visited2[next_r][next_c] && pic[next_r][next_c] == color)
						{
//							cout << "target_color, next_r, next_c, next_color : "
//								<< color 
//								<< ", "
//								<< next_r
//								<< ", "
//								<< next_c
//								<< ", "
//								<< pic[next_r][next_c] << "\n";
							q.push(make_pair(next_r, next_c));
							visited2[next_r][next_c] = 1;
						}
					}
				}
			}
		}
	}
	cout << area;
	//no red green

	return (0);
}

