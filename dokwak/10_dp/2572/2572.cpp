#include <bits/stdc++.h>

using namespace std;
using info = pair<int, int>; //node, color;
int n, m;
int rec(int idx, int cur, vector<vector<info>> &g, vector<vector<int>> &dp, vector<int> &cards){
  if (idx == cards.size()) return 0;
  if (dp[idx][cur] != -1) return (dp[idx][cur]);
  int &ret = dp[idx][cur];
  ret = 0;
  int cur_card_color = cards[idx];
  for (auto info_ : g[cur]){
    auto [next, color] = info_;
    int score = color == cur_card_color ? 10 : 0;
    ret = max(ret, rec(idx + 1, next, g, dp, cards) + score);
  }
  //cout << "idx, cur" << idx << ", " << cur << ", "<< ret <<"\n";
  return (ret);
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unordered_map<char, int> colorToNum = {{'R', 0}, {'G', 1}, {'B', 2}};
  cin >> n;
  vector<int> cards(n);
  for (int i = 0; i < n; i++) {
    char card;
    cin >> card;
    cards[i] = colorToNum[card];
  }
  int nodes, edge;
  cin >> nodes >> edge;
  vector<vector<int>> dp(n + 1, vector<int>(nodes + 1, -1));
  vector<vector<info>> g(nodes + 1);
  for (int i = 0; i < edge; i++) {
    int u, v, color_num;
    char color;
    cin >> u >> v >> color;
    color_num = colorToNum[color];
    g[u].push_back({v, color_num});
    g[v].push_back({u, color_num});
  }
  int sol = rec(0, 1, g, dp, cards);
  cout << sol;
  return (0);
}

