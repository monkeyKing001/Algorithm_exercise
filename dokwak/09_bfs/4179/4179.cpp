#include <vector>
#include <iostream>
#include <cmath> 
#include <algorithm>
#include <climits>
#include <map>
#include <string>

using namespace std;
char maps[1001][1001];
int j_step, f_step;
pair <int, int> j_start;
pair <int, int> f_start;
int r, c;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

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
	return (0);
}

