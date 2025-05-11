#include <bits/stdc++.h>

using namespace std;
using info = tuple<int, int, int, int>; //num, g, s, c

int n, m;

bool cmp(tuple<int, int, int, int> info1, tuple<int, int, int, int> info2){
  auto [num1, g1, s1, c1] = info1;
  auto [num2, g2, s2, c2] = info2;
  if (g1 != g2) return (g1 > g2);
  if (s1 != s2) return (s1 > s2);
  if (c1 != c2) return (c1 > c2);
  return (false);
}

bool cmp2(tuple<int, int, int, int> info1, tuple<int, int, int, int> info2){
  auto [num1, g1, s1, c1] = info1;
  auto [num2, g2, s2, c2] = info2;
  if (g1 != g2 || s1 != s2 || c1 != c2) return (false);
  return (true);
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<info> infos(n);
  for (int i = 0; i < n; i++) {
    int num, g, s, c;
    cin >> num >> g >> s >> c;
    infos[i] = {num, g, s, c};
  }
  sort(infos.begin(), infos.end(), cmp);
  int rank_ = 0;
  unordered_map<int, int> ranks;
  info prv = {-1, -1, -1, -1};
  int eq = 1;
  for (auto info: infos){
    auto [num, g, s, c] = info;
    if (cmp2(prv, info)){
      eq++;
    }
    else {
      rank_ += eq;
      eq = 1;
    }
    ranks[num] = rank_;
//    cout
//      << num
//      << ", "
//      << g
//      << ", "
//      << s
//      << ", "
//      << c
//      << "\n";
    if (num == m){ cout << rank_ << "\n"; return (0); }
    prv = info;
  }
  return (0);
}

