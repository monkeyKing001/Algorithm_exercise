#include <bits/stdc++.h>
using namespace std;
using info = pair<int, int>;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> dp(n + 2, 0);
  vector<info> infos(n + 1);
  for (int i = 1; i < n + 1; i++)
    cin >> infos[i].first >> infos[i].second;
  int ans = 0;
  for (int i = 1; i <= n; i++){
    auto [cost_time, prize] = infos[i];
    if (i > 0)
      dp[i] = max(dp[i - 1], dp[i]);
    int start_prize = dp[i];
    int target_day = i + cost_time;
    if (target_day <= n + 1)
      dp[target_day] = max(dp[target_day], prize + start_prize);
  }
  dp[n + 1] = max(dp[n + 1], dp[n]);
  cout << dp.back();
  return (0);
}

