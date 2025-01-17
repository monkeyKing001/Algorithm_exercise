#include <bits/stdc++.h>
#include <queue>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  priority_queue<int> pq;
  vector<int> cards(n, 0);
  for (int i = 0; i < n; i++) cin >> cards[i];
  sort(cards.rbegin(), cards.rend());
  int ans = 0;
  for (int i = 0; i < n && m--; i++) {
    int j = n - 1 - i;
    if (i > j)
      break;
    if (cards[i] < 0)
      break;
    ans += cards[i];
  }
  cout << ans;
  return (0);
}

