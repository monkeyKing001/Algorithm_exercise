#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using rot_info = tuple<int, int, int>;
int n, m, k;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int sol = INT_MAX;

void cal(vector<vector<int>> &arr){
  for (int i = 1; i < arr.size(); i++){
    auto &rows = arr[i];
    partial_sum(rows.begin(), rows.end(), rows.begin());
    sol = min(sol, rows.back());
  }
}

void rotate_clockwise_recur(vector<vector<int>> &arr, rot_info &info){
  auto &[center_r, center_c, s] = info;
  if (s == 0) return;
  int start_r = center_r - s, start_c = center_c - s;
  int r = start_r, c = start_c;
  int pop_num = arr[r][c], next_pop_num = arr[r][c];
  int di = 0;
  int move_count = (s * 2) + 1;
  int cur_move = 1;
  do{
    if (cur_move == move_count){
      di++;
      cur_move = 1;
    }
    cur_move++;
    int next_r = r + dr[di], next_c = c + dc[di];
    next_pop_num = arr[next_r][next_c];
    arr[next_r][next_c] = pop_num;
    pop_num = next_pop_num;
    r = next_r; c = next_c;
  } while (r != start_r || c != start_c);
  s--;
  rotate_clockwise_recur(arr, info);
}

void rotate_with_info(vector<vector<int>> &arr, vector<rot_info> &rots, int idx){
  rotate_clockwise_recur(arr, rots[idx]);
}

void rotate(vector<vector<int>> &arr, vector<rot_info> rots, vector<int> &order){
  for (auto idx : order) rotate_with_info(arr, rots, idx);
  cal(arr);
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i < n + 1; i++) 
    for (int j = 1; j < m + 1; j++) cin >> arr[i][j];
  vector<int> rot_order(k, 0);
  vector<rot_info> rotations(k);
  for (int i = 0; i < k; i++) {
    int r, c, s;
    cin >> r >> c >> s;
    rotations[i] = {r, c, s};
    rot_order[i] = i;
  }
  do{
    auto cp = arr;
    rotate(cp, rotations, rot_order);
  } while(next_permutation(rot_order.begin(), rot_order.end()));
  cout << sol;
  return (0);
}

