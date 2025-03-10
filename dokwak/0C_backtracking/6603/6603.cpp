#include <bits/stdc++.h>

using namespace std;
int n, m;
void rec(int idx, int prev_num_idx, vector<int> &nums, vector<int> &buf){
  if (idx == 6){
    for (auto b: buf) cout << b << " ";
    cout << "\n";
    return ;
  }
  for (int i = prev_num_idx + 1; i < nums.size(); i++){
    buf[idx] = nums[i];
    rec(idx + 1, i, nums, buf);
  }
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> buf(6, -1);
  int tok;
  cin >> tok;
  while (tok){
    vector<int> nums(tok, 0);
    for (int i = 0; i < tok; i++) cin >> nums[i];
    rec(0, -1, nums, buf);
    cout << "\n";
    cin >> tok;
  }
  return (0);
}

