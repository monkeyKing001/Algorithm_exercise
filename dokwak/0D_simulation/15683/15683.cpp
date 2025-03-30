#include <bits/stdc++.h>

using namespace std;
using cctv_info = tuple<int, int, int>;//r, c, dir
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int n, m;
int sol = INT_MAX;
vector<cctv_info> cctvs; //cctv, cctc direction
vector<vector<int>> room;

void count_area(){
  int undetected_area = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (room[i][j] == 0) undetected_area++;
    }
  }
  sol = min(sol, undetected_area);
}

void side_wide_family_cam_detect(cctv_info info, int wide_num){
  auto [r, c, dir] = info;
  int start_r = r, start_c = c;
  int offset = 1;
  if (room[r][c] == 2) offset = 2;//cctv 2 offset is 2.
  for (int dir_count = 0; dir_count < wide_num; dir_count++) {
    dir += offset;
    dir %= 4;
    while(r >= 0 && r < n && c >= 0 && c < m){
      if (room[r][c] == 6) break;
      if (room[r][c] == 0) room[r][c] = '#';
      r += dr[dir];
      c += dc[dir];
    }
    r = start_r, c = start_c;
  }
}

void cam_detect_simulation(){
  vector<vector<int>> cp_arr_backup = room;
  for (int i = 0; i < cctvs.size(); i++){
    auto cctv_info = cctvs[i];
    auto [r, c, di] = cctv_info;
    side_wide_family_cam_detect(cctv_info, room[r][c]);
  }
  count_area();
  room = cp_arr_backup;
}

void rec(int idx){
  if (idx == cctvs.size()){
    cam_detect_simulation();
    return;
  }
  auto &[r, c, dir] = cctvs[idx];
  for (int i = 0; i < 4; i++){
    dir = i;
    rec(idx + 1);
  }
}

void simulation(){
  rec(0);
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  room.resize(n, vector<int> (m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> room[i][j];
      if (room[i][j] > 0 && room[i][j] < 6) cctvs.push_back({i, j, 0});
    }
  }
  simulation();
  cout << sol;
  return (0);
}

