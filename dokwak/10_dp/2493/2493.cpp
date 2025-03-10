#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  stack<int> s;
  vector<int> tower_(n, 0);
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++) cin >> tower_[i];
  for (int i = 0; i < n; i++){
    while (s.size() != 0 && tower_[s.top()] <= tower_[i]) s.pop();
    if (s.size() != 0 && tower_[s.top()] > tower_[i]) ans[i] = s.top() + 1;
    s.push(i);
  }
  for (auto a : ans) cout << a << " ";
  return (0);
}

