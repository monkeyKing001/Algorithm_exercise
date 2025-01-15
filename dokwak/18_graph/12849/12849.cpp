#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int mod = 1e9 + 7;
  int node_num = 8, edge_num = 12;
  vector<vector<int>> g(node_num);
  g[0] = {1, 2}, g[1] = {0, 2, 3}, g[2] = {0, 1, 3, 4}, g[3] = {1, 2, 4, 5};
  g[4] = {2, 3, 5, 6}, g[5] = {3, 4, 7}, g[6] = {4, 7}, g[7] = {5, 6};
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(8, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++){
//    cout << "stage : " << i << "\n";
    for (int j = 0; j < 8; j++) {
      int cur_node = j;
      for (int k = 0; k < g[cur_node].size(); k++) {
         int adj_node = g[cur_node][k];
        dp[i][cur_node] += dp[i - 1][adj_node];
        dp[i][cur_node] %= mod;
      }
//      cout << "node, count : "<< cur_node << ", " << dp[i][cur_node] << "\n";
    }
  }
  cout << dp[n][0];
  return (0);
}

