#include <iostream>

using namespace std;

int n, m;
long long board[1030][1030];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int input;
      cin >> input;
      board[i][j] = board[i-1][j] + board[i][j-1] - board[i-1][j-1] + input;
    }
  }
  for (int i = 0; i < m; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    long long res = board[x2][y2] - board[x1-1][y2] - board[x2][y1-1] + board[x1-1][y1-1];
    cout << res << '\n';
  }
}
