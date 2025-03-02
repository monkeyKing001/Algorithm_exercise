#include <bits/stdc++.h>

using namespace std;
int n, m;

void rec(int idx, set<int> &nums, vector<int> &buf){
  if (idx == m){
    for (auto elm : buf) cout << elm << " ";
    cout << "\n";
    return;
  }
  for (auto &n : nums){
    if (idx > 0 && n < buf[idx - 1]) continue;
    buf[idx] = n;
    rec(idx + 1, nums, buf);
  }
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  map<int, int> nums;
  vector<int> buf(m, -1);
  set<int> s;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    s.insert(num);
    nums[num]++;
  }
  rec(0, s, buf);
  return (0);
}

