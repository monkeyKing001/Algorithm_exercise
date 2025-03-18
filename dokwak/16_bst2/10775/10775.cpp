#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  set<int> airport;
  for (int i = 1; i < n + 1; i++) {
    airport.insert(i);
  }
  int count = 0;
  for (int i = 0; i < m; i++, count++) {
    int num = 0;
    cin >> num;
    if (!airport.size()) break;
    auto it = airport.lower_bound(num);
    if (it == airport.begin() && *it > num) break;
    else if (it != airport.end() && *it == num) airport.erase(num);
    else airport.erase(*(--it));
  }
  cout << count;
  return (0);
}

