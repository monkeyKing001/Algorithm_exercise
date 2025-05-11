#include <bits/stdc++.h>

using namespace std;
using info = pair<int, int>;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  priority_queue<info> pq;
  int dasom = 0;
  for (int i = 1; i < n + 1; i++) {
    int vote, id = i;
    cin >> vote;
    pq.push({vote, id});
    if (id == 1) dasom = vote;
  }
  int buy = 0;
  while (true){
    auto [vote, id] = pq.top(); 
    pq.pop();
    if (vote < dasom || id == 1) break;
    dasom++, vote--;
    pq.push({vote, id});
    buy++;
  }
  cout << buy;
  return (0);
}

