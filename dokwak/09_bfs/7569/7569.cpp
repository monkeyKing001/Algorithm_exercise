#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int dr[6] = {-1, 0, 1, 0, 0, 0};
int dc[6] = {0, 1, 0, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};
int box[100][100][100];
vector <tuple <int, int, int>> coord;
queue <tuple <int, int, int>> q;
int n, m, h, days;
int r, c;
int unrip;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> r >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				cin >> box[j][k][i];
				if (box[j][k][i] == 1)
					q.push(make_tuple(j, k, i));
				else if (box[j][k][i] == 0)
					unrip++;
			}
		}
	}
//	for (int i = 0; i < coord.size(); i++)
//	{
//		int s_r = get<0>(coord[i]);
//		int s_c = get<1>(coord[i]);
//		int s_h = get<2>(coord[i]);
//		q.push(make_tuple(s_r, s_c, s_h));
////		cout
////			<< s_r
////			<< ", "
////			<< s_c
////			<< ", "
////			<< s_h
////			<< "\n";
//	}
	while (q.size())
	{
		int c_r = get<0>(q.front());
		int c_c = get<1>(q.front());
		int c_h = get<2>(q.front());
		int c_d = box[c_r][c_c][c_h];
		q.pop();
//		cout << "front() : ";
//		cout
//			<< c_r
//			<< ", "
//			<< c_c
//			<< ", "
//			<< c_h
//			<< ": "
//			<< box[c_r][c_c][c_h]
//			<< "\n";
		for (int j = 0; j < 6; j++)
		{
			int n_r = c_r + dr[j];
			int n_c = c_c + dc[j];
			int n_h = c_h + dh[j];
//				cout
//					<< n_r
//					<< ", "
//					<< n_c
//					<< ", "
//					<< n_h
//					<< "\n";
			if (n_r > -1 && n_r < r && n_c > -1 && n_c < c && n_h > -1 && n_h < h
					&&!box[n_r][n_c][n_h]
					)
			{
//				cout
//					<< "now "
//					<< n_r
//					<< ", "
//					<< n_c
//					<< ", "
//					<< n_h
//					<< " = "
//					<< c_d + 1
//					<< "\n";
				box[n_r][n_c][n_h] = c_d + 1;
				q.push(make_tuple(n_r, n_c, n_h));
				unrip--;
				if (c_d + 1 > days)
					days = c_d;
			}
		}
	}
//	for (int i = 0; i < h; i++)
//	{
//		for (int j = 0; j < r; j++)
//		{
//			for (int k = 0; k < c; k++)
//			{
//				cout << box[j][k][i] << " ";
//			}
//			cout << "\n";
//		}
//		cout << "\n";
//	}
	if (unrip)
	{
		cout << -1;
		return (0);
	}
	cout << days;
	return (0);
}
