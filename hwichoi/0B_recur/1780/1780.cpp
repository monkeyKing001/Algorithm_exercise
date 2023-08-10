#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int n;
int board[5000][5000];

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
	return (0);
}

