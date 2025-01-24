#include <bits/stdc++.h>

using namespace std;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<int> ans;
  vector<vector<int>> g(n + 1);
  vector<int> in(n + 1, 0);
  ans.reserve(n);
  for (int i = 0; i < m; i++) {
    int count, cur_node;
    cin >> count >> cur_node;
    for (int j = 0; j < count - 1; j++) {
      int to_node;
      cin >> to_node;
      g[cur_node].push_back(to_node);
      in[to_node]++;
      cur_node = to_node;
    }
  }
  queue<int> q;
  for (int i = 1 ; i < n + 1; i++)
    if (!in[i]) q.push(i);
  while (q.size()){
    int cur_node = q.front();
    ans.push_back(cur_node);
    q.pop();
    for (auto next : g[cur_node]){
      in[next]--;
      if (!in[next]) q.push(next);
    }
  }
  string buf;
  buf.reserve(4000);
  if (ans.size() != n) buf = "0";
  else for (auto num : ans) buf += to_string(num) + "\n";
  cout << buf;
  return (0);
}

