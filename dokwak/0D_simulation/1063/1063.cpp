#include <bits/stdc++.h>

using namespace std;
using pos = pair<int, int>;
int n, m;
int dr[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dc[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

void move_movable(int dir, pos &cur_pos){
  auto &[r, c] = cur_pos;
  r += dr[dir], c += dc[dir];
}

bool movable_(int dir, pos cur_pos){
  auto [r, c] = cur_pos;
  int next_r = r + dr[dir];
  int next_c = c + dc[dir];
  return (next_r >= 0 && next_r < 8 && next_c >= 0 && next_c < 8);
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unordered_map<string, int> move_info = {
    {"R", 0}, {"L", 1}, {"B", 2}, {"T", 3},
    {"RT", 4}, {"LT", 5}, {"RB", 6}, {"LB", 7} };
  string king_pos_str, stone_pos_str;
  cin >> king_pos_str >> stone_pos_str;
  int move_count = 0;
  cin >> move_count;
  pos king_pos, stone_pos;
  king_pos.first = 7 - (king_pos_str[1] - '1');
  king_pos.second = (king_pos_str[0] - 'A');
  stone_pos.first = 7 - (stone_pos_str[1] - '1');
  stone_pos.second = (stone_pos_str[0] - 'A');
  auto &[king_r, king_c] = king_pos;
  auto &[stone_r, stone_c] = stone_pos;
  for (int i = 0; i < move_count; i++) {
    string move_info_input;
    cin >> move_info_input;
    int move_dir = move_info[move_info_input];
    auto [king_r, king_c] = king_pos;
    auto [stone_r, stone_c] = stone_pos;
    int next_king_r = king_r + dr[move_dir];
    int next_king_c = king_c + dc[move_dir];
    //if there is stone, move stone first
    if (next_king_r == stone_r && next_king_c == stone_c){
      if (movable_(move_dir, stone_pos)){
        move_movable(move_dir, stone_pos);
        move_movable(move_dir, king_pos);
      }
    }
    else if (movable_(move_dir, king_pos)) move_movable(move_dir, king_pos);
  }
  cout << (char)(king_c + 'A') << (8 - king_r) << "\n";
  cout <<(char)(stone_c + 'A') << (8 - stone_r) << "\n";
  return (0);
}

