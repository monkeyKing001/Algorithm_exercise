#include <bits/stdc++.h>

using namespace std;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<int> prefix_sum(n, 0);
  for (int i = 0; i < n; i++) cin >> prefix_sum[i];
  partial_sum(prefix_sum.begin(), prefix_sum.end(), prefix_sum.begin());
  int l = 0, r = 0;
  int sum = 0, sol = 0;
  while (l < n && r < n){
    int sum = l > 0 ? prefix_sum[r] - prefix_sum[l - 1] : prefix_sum[r];
    if (sum == m) sol++;
    if (sum >= m) l++;
    else r++;
  }
  cout << sol;
  return (0);
}

