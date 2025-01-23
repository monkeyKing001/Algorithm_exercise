#include <bits/stdc++.h>
#define RED 0
#define GREEN 1
#define BLUE 2
#define RED_START 0
#define GREEN_START 1
#define BLUE_START 2

using namespace std;
int max_cost = 1e7;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int cost[n][3];
  for (int i = 0; i < n; i++) cin >> cost[i][RED] >> cost[i][GREEN] >> cost[i][BLUE];
  vector<vector<vector<int>>>dp(3, vector<vector<int>>(n, vector<int> (3, max_cost)));
  dp[RED_START][0][RED] = cost[0][RED];
  dp[GREEN_START][0][GREEN] = cost[0][GREEN];
  dp[BLUE_START][0][BLUE] = cost[0][BLUE];

  for (int i = 1; i < n - 1; i++){//house index i
    for (int sci = 0; sci < 3; sci++){//start_color_index
      for (int ci = 0; ci < 3; ci++){ //color_index
        dp[sci][i][ci] = min(dp[sci][i - 1][(ci + 1) % 3], dp[sci][i - 1][(ci + 2) % 3]) + cost[i][ci];
      }
    }
  }
  int sol = max_cost;
  for (int sci = 0; sci < 3; sci++){//start_color_index
    for (int ci = 0; ci < 3; ci++){ //color_index
      if (sci == ci)
        continue;
      dp[sci][n - 1][ci] = min(dp[sci][n - 2][(ci + 1) % 3], dp[sci][n - 2][(ci + 2) % 3]) + cost[n - 1][ci];
      sol = min(sol, dp[sci][n - 1][ci]);
    }
  }
	cout << sol;
	return (0);
}
