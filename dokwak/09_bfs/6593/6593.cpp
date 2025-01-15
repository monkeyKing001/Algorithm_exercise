#include <bits/stdc++.h>

using namespace std;
using pos = tuple<int, int, int>;
int n, m;
int dr[6] = {1, 0, -1, 0, 0, 0};
int dc[6] = {0, -1, 0, 1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int h = 0;
  cin >> h >> n >> m;
  while (h != 0 && n != 0 && m != 0){
    pos start;
    vector<vector<vector<int>>> map_(h, vector<vector<int>> (n, vector<int>(m, 0)));
    vector<vector<vector<int>>> count(h, vector<vector<int>> (n, vector<int>(m, -1)));
    string buf;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < n; j++) {
        cin >> buf;
        for (int k = 0; k < m; k++) {
          map_[i][j][k] = buf[k];
          if (map_[i][j][k] == 'S')
            start = {i, j, k};
        }
      }
    }
    queue<pos> q;
    int step = -1;
    auto [start_h, start_r, start_c] = start;
    count[start_h][start_r][start_c] = 0;
    q.push(start);
    while (q.size()){
      auto [cur_h, cur_r, cur_c] = q.front();
      q.pop();
      for (int d_i = 0; d_i < 6; d_i++) {
        int next_h = cur_h + dh[d_i];
        int next_r = cur_r + dr[d_i];
        int next_c = cur_c + dc[d_i];
        if (next_h >= 0 && next_h < h &&\
            next_r >= 0 && next_r < n &&\
            next_c >= 0 && next_c < m &&\
            map_[next_h][next_r][next_c] != '#' &&\
            count[next_h][next_r][next_c] == -1)
        {
          count[next_h][next_r][next_c] = count[cur_h][cur_r][cur_c] + 1;
          if (map_[next_h][next_r][next_c] == 'E'){
            step = count[next_h][next_r][next_c];
            break;
          }
          q.push({next_h, next_r, next_c});
        }
      }
    }
    if (step == -1)
      cout << "Trapped!\n"; 
    else
      cout <<"Escaped in " << step <<" minute(s).\n"; 
    cin >> h >> n >> m;
  }
  return (0);
}

