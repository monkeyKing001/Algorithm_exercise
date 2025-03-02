#include <bits/stdc++.h>

using namespace std;
using pos = pair<int, int>;
int n, m;

int dr[4] = {0, 1, -1, 0};
int dc[4] = {1, 0, 0, -1};

int sol;

vector<vector<int>> map_(501, vector<int>(501, 0));
vector<vector<int>> dp(501, vector<int>(501, -1));

int rec(pos p){
  auto [r, c] = p;
  if (dp[r][c] > -1) return dp[r][c];
  int &result = dp[r][c];
  result = 1;
  for (int di = 0; di < 4; di++) {
    int next_r = r + dr[di]; 
    int next_c = c + dc[di]; 
    if (next_r >= 0 && next_r < n && \
        next_c >= 0 && next_c < n && \
        map_[next_r][next_c] > map_[r][c])
      result = max(result, rec({next_r, next_c}) + 1);
  }
  return (result);
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) 
      cin >> map_[i][j];

  //sol
  //not visited, travel start;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) 
      if (dp[i][j] < 0) sol = max(sol, rec({i, j}));
	cout << sol;
	return (0);
}

