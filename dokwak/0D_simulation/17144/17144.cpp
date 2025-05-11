#include <bits/stdc++.h>

using namespace std;
using pos = pair<int, int>;
using dif_info = tuple<int, int, int>; //r, c, offset;
int n, m;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};
int clock_dr[4] = {-1, 0, 1, 0};
int clock_dc[4] = {0, 1, 0, -1};
int anti_clock_dr[4] = {1, 0, -1, 0};
int anti_clock_dc[4] = {0, 1, 0, -1};

int count(vector<vector<int>> &arr){
  int num = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] != -1) num+=arr[i][j];
    }
  }
  return (num);
}

void diffusion_cell(vector<vector<int>> &arr, pos cell, vector<dif_info> &difs){
  auto [r, c] = cell;
  int mun = arr[r][c];
  int count = 0;
  for (int di = 0; di < 4; di++) {
    int nr = r + dr[di];
    int nc = c + dc[di];
    if (nr >= 0 && nr < n && nc >= 0 && nc < m && arr[nr][nc] != -1){
      difs.push_back({nr, nc, mun / 5});
      count++;
    }
  }
  difs.push_back({r, c, (-mun / 5) * count});
}

void diffusion(vector<vector<int>> &arr){
  //stack diffusion info
  vector<dif_info> difs;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] != -1 && arr[i][j]) diffusion_cell(arr, {i, j}, difs);
    }
  }
  //execute diffusion
  for (auto [r, c, offset] : difs) arr[r][c] += offset;
}

void cleanOneDir(vector<vector<int>> &arr, const pos cleaner, bool clock_wise){
  auto [start_r, start_c] = cleaner;
  int *cur_dr = clock_wise ? clock_dr : anti_clock_dr;
  int *cur_dc = clock_wise ? clock_dc : anti_clock_dc;
  int di = 0;
  int cur_r = start_r + cur_dr[di];
  int cur_c = start_c + cur_dc[di];
  while (true){
    int next_r = cur_r + cur_dr[di];
    int next_c = cur_c + cur_dc[di];
    bool change_dir = false;
    if (next_r == start_r && next_c == start_c) break;
    if (clock_wise){
      if (next_r < 0 || next_r == start_r + 1 || next_c < 0 || next_c == arr[0].size())
        change_dir = true;
    }
    else{
      if (next_r == arr.size() || next_r == start_r - 1 || next_c < 0 || next_c == arr[0].size())
        change_dir = true;
    }
    if (change_dir){
      di++;
      di %= 4;
      continue;
    }
    arr[cur_r][cur_c] = arr[next_r][next_c];
    cur_r = next_r, cur_c = next_c;
  }
  arr[cur_r][cur_c] = 0;
}

void cleaning(vector<vector<int>> &arr, const vector<pos> &cleaners){
  cleanOneDir(arr, cleaners[0], true);
  cleanOneDir(arr, cleaners[1], false);
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int time;
  cin >> n >> m >> time;
  vector<vector<int>> area(n, vector<int> (m, 0));
  vector<pos> cleaners;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> area[i][j];
      if (area[i][j] == -1) cleaners.push_back({i, j});
    }
  }
  for (int i = 0; i < time; i++) {
    diffusion(area);
    cleaning(area, cleaners);
  }
  cout << count(area);
  return (0);
}

