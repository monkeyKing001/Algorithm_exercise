#include <bits/stdc++.h>

using namespace std;
int n;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n; 
  vector <int> nums(n + 1, INT_MAX);
  queue<pair<int, int>>q;
  q.push({1, 0});
  nums[1] = 0;
  while (q.size() && nums[n] == INT_MAX){
    auto [num, steps] = q.front();
    q.pop();
    for (int i = 0; i < 3; i++) {
      int next_num = num + 1;
      if (i == 1) next_num = num * 2;
      if (i == 2) next_num = num * 3;
      if (next_num <= n && nums[next_num] == INT_MAX) {
        nums[next_num] = steps + 1;
        q.push({next_num, steps + 1});
      }    
    }
  }
  cout << nums[n];
	return (0);
}
