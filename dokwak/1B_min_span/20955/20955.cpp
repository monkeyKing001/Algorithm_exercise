#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> p;

int find_p(int u){
  if (p[u] == -1) return u;
  p[u] = find_p(p[u]);
  return (p[u]);
}

void union_uv(int u, int v){
  int p_u = find_p(u);
  int p_v = find_p(v);
  if (p_u > p_v){
    int temp = p_u;
    p_u = p_v;
    p_v = temp;
  }
  p[p_v] = p_u;
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  p.resize(n + 1, -1);
  int drop_out_count = 0, link_sub_tree_count = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    int p_u = find_p(u), p_v = find_p(v);
    if (p_u == p_v) drop_out_count++;
    else union_uv(u, v);
  }
  unordered_set<int> subtree_root;
  for (int i = 1; i <= n; i++) 
    subtree_root.insert(find_p(i));
  cout << drop_out_count + subtree_root.size() - 1; 
  //count sub tree;
  return (0);
}

