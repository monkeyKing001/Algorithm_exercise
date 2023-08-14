#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
char board[10000][10000];
string s[3] = {"*****", " * * ", "  *  "};

void recur(int n, int x, int y) {
	if (n == 3) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 5; ++j) {
				board[x-i][y+j] = s[i][j];
			}
		}
		return;
	}
	recur(n/2, x, y);
	recur(n/2, x, y + n);
	recur(n/2, x - n/2, y + n/2);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		fill(board[i], board[i] + n*2, ' ');
	recur(n, n-1, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n*2; ++j) {
			cout << board[i][j];
		}
		cout << '\n';
	}
	return (0);
}

