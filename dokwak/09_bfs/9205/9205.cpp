#include <bits/stdc++.h>

using namespace std;
using pos = pair<int, int>;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<pos> points(n + 2);
    for (int i = 0; i < n + 2; i++){
      auto &[x, y] = points[i];
      cin >> x >> y;
    }
    vector<bool> visited(n + 2, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    bool happy = false;
    
    while(!q.empty()){
      int current = q.front();
      q.pop();
      //arrive fest
      if(current == n + 1){
        happy = true;
        break;
      }
      for(int i = 0; i < n + 2; i++){
        if(!visited[i]){
          int distance = abs(points[current].first - points[i].first)
                       + abs(points[current].second - points[i].second);
          if(distance <= 1000){
            visited[i] = true;
            q.push(i);
          }
        }
      }
    }
    cout << (happy ? "happy" : "sad") << "\n";
  }
  return (0);
}

