#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;
int limit = 1e6;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<int> prefix_sum(limit + 1, 0);
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    for (int j = start + 1; j <= end; j++) prefix_sum[j]++;
  }
  partial_sum(prefix_sum.begin(), prefix_sum.end(), prefix_sum.begin());
  int l = 0, r = l;
  ll cur_sum = prefix_sum[r];
  while (l <= r && l <= limit && r <= limit){
    if (l == 0) cur_sum = prefix_sum[r];
    else cur_sum = prefix_sum[r] - prefix_sum[l];
    if (cur_sum == m) break;
    else if (cur_sum < m) r++;
    else if (cur_sum > m) l++;
  }
  if (cur_sum != m) l = 0, r = 0;
  cout << l << " " << r;
  return (0);
}

