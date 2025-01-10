#include <bits/stdc++.h>
#define POS first
#define COUNT second
using namespace std;
using point = pair<int, int>;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  unordered_map<int, int> x_count;
  unordered_map<int, int> y_count;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x_count[x]++;
    y_count[y]++;
  }
  int ans = 0;
  for (auto x_info : x_count){
    if (x_info.COUNT >= 2) ans++;
  }
  for (auto y_info : y_count){
    if (y_info.COUNT >= 2)
      ans++;
  }
  cout << ans;
  return (0);
}

