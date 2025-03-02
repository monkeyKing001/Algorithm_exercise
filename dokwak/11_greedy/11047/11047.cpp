#include <bits/stdc++.h>

using namespace std;
int n, k;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  vector<int> coins(n);
  for (int i = 0; i < n; i++) 
    cin >> coins[i];
  int total_count = 0;
  auto cur_coin_it = coins.end() - 1;
  while (k){
    if (*cur_coin_it > k){
      cur_coin_it--;
      continue;
    }
    total_count += k / *cur_coin_it;
    k -= (k / *cur_coin_it) * (*cur_coin_it);
  }
  cout << total_count;
  return (0);
}

