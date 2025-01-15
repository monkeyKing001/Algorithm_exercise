#include <bits/stdc++.h>
#define ll long long
#define COST first
#define PAYOFF second

using namespace std;
using info = pair<ll, ll>;
ll n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<info> infos(n);
  for (int i = 0; i < n; i++) 
    cin >> infos[i].COST;
  for (int i = 0; i < n; i++) 
    cin >> infos[i].PAYOFF;
  sort(infos.begin(), infos.end());
  for (auto i : infos){
    auto [cost, payoff] = i;
    if (cost > m)
      break;
    if (cost >= payoff)
      continue;
    m += (payoff - cost);
  }
  cout << m;
  return (0);
}

