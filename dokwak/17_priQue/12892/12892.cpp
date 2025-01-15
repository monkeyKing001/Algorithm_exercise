#include <bits/stdc++.h>
#define ll long long
#define PRICE first
#define VALUE second

using namespace std;
using info = pair<ll, ll>;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  deque<info> bag;
  int d = 0;
  ll temp = 0;
  ll ans = 0;
  cin >> n >> d;
  vector<info> presents(n);
  for (int i = 0; i < n; i++) 
    cin >> presents[i].PRICE >> presents[i].VALUE;
  sort(presents.begin(), presents.end());
  for (auto p : presents){
    auto [price, value] = p;
    while (bag.size() != 0 && (price - bag.front().PRICE) >= d)
     temp -= bag.front().VALUE, bag.pop_front();
    bag.push_back(p), temp += value;
    ans = max(ans, temp);
  }
  cout << ans;
  return (0);
}

