#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	char map[n][m];
	for (int i = 0; i < n; i++)
	{
		string str = "";
		cin >> str;
		for (int j = 0; j < m; j++)
			map[i][j] = str[j];
	}
	int max = -1;
	for (int i = 1; i <= min(n, m); i++) {
		int len = i;
		for (int r = 0; r + len -1 < n; r++)
		{
			for (int c = 0; c + len - 1 < m; c++)
			{
				if (
						map[r][c] == map[r + len - 1][c]
						&&
						map[r + len - 1][c] == map[r + len - 1][c + len - 1]
						&&
						map[r + len - 1][c + len - 1] == map[r][c + len - 1]
						){
					max = len;
					break;
				}
			}
		}
	}
	cout << max * max;
	return (0);
}

