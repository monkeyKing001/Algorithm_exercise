#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x, y, w, s;
  cin >> x >> y >> w >> s;
  
  long long cost1 = (x + y) * w;

  long long d = min(x, y);
  long long rem = max(x, y) - d;
  long long cost2 = d * s + rem * w;
  
  long long cost3;
  if(rem % 2 == 0)
      cost3 = max(x, y) * s;
  else
      cost3 = (max(x, y) - 1) * s + w;
  
  long long ans = min({cost1, cost2, cost3});
  cout << ans << "\n";
  
  return (0);
}

