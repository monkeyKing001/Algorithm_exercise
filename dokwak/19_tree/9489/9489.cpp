#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int node_num = 1, target_cousin = -1;
  cin >> node_num >> target_cousin;
  while (node_num && target_cousin){
    vector<int> nodes(node_num);
    unordered_map<int, int> parent;
    map<int, vector<int>> g;
    g[nodes[0]] = {};
    parent[nodes[0]] = 0;
    for (int i = 0; i < node_num; i++) cin >> nodes[i];
    //make tree
    for (int i = 1; i < node_num; i++) {
      int ii = i;
      while (ii + 1 != node_num && nodes[ii] == nodes[ii + 1] - 1) ii++;
      //make subtree
      int cur_parent = 0;
      for (auto &[n, v] : g){
        if (!v.size()){
          cur_parent = n;
          g[n].assign(nodes.begin() + i, nodes.begin() + ii + 1);
          break;
        }
      }
      for (int j = i; j <= ii; j++) {
        g[nodes[j]] = {};
        parent[nodes[j]] = cur_parent;
      }
      i = ii;
    }
    //get cousin
    int cousin_parent = parent[target_cousin];
    int cousin_num = 0;

    //if target cousin is root or level 1, no cousin
    if (parent[target_cousin] != target_cousin && 
      parent[parent[cousin_parent]] != parent[target_cousin]){
      int ancestor = parent[parent[target_cousin]];
      for (int p_i = 0; p_i < g[ancestor].size(); p_i++){
        if (g[ancestor][p_i] != parent[target_cousin]) cousin_num += g[g[ancestor][p_i]].size();
      }
    }
    cout << cousin_num << "\n";
    cin >> node_num >> target_cousin;
  }
  return (0);
}

