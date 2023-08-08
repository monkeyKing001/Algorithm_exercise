#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int n, k;
int board[100002];
queue<int> Q;
#define MAX 100002

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	fill(board, board + MAX, -1);
	board[n] = 0;
	Q.push(n);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		if (cur == k) {
			cout << board[k] << '\n';
			return 0;
		}
		int a, b, c;
		a = cur + 1;
		b = cur - 1;
		c = cur * 2;
		if (a >= 0 && a < MAX && board[a] == -1) {
			board[a] = board[cur] + 1;
			Q.push(a);
		}
		if (b >= 0 && b < MAX && board[b] == -1) {
			board[b] = board[cur] + 1;
			Q.push(b);
		}
		if (c >= 0 && c < MAX && board[c] == -1) {
			board[c] = board[cur] + 1;
			Q.push(c);
		}
	}
	return (0);
}

