#include <iostream>

using namespace std;

int n, m;
char arr[202][202];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> arr[i][j];
}
