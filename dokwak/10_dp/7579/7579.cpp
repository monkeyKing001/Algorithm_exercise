#include <bits/stdc++.h>

using namespace std;
using info = pair<int, int>;
int n, m;
int sol = INT_MAX;
vector<vector<int>> dp(101, vector<int>(10001, 0)); //r = app i, c = total cost;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n; //app num
	cin >> m; //need memory
  vector<int> mems(n);
  vector<int> costs(n);
  vector<pair<int, int>> apps(n);
  for (int i = 0; i < n; i++) cin >> apps[i].first;
  for (int i = 0; i < n; i++) cin >> apps[i].second;
  int sol = INT_MAX;
  for (int i = 0; i < n; i++) {
    auto [mem, cost] = apps[i];
    if (i == 0){
      dp[0][cost] = mem;
      continue;
    }  
    else{
      dp[i] = dp[i - 1];
      for (int j = 0; j < dp[i].size(); j++){
        if (j + cost < dp[i].size()) dp[i][j + cost] = max(dp[i][j + cost], dp[i - 1][j] + mem);
      }
    }
  }
  for (int i = 0; i < dp.back().size() && sol == INT_MAX; i++) 
    if (dp[n - 1][i] >= m) sol = i;
  cout << sol;
  return (0);
}
