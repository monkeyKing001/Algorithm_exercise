#include <bits/stdc++.h>

using namespace std;

using task = pair<int, int>;

int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int t_i = 0; t_i < T; t_i++) {
    int number, target;
    cin >> number >> target;
    queue<task> q;
    map<int, int> pri;
    for (int i = 0; i < number; i++) {
      int priority;
      cin >> priority;
      q.push({i, priority});
      pri[-priority]++;
    }
    int count = 0;
    int max_count = number * number;
    while (q.size() && count < max_count){
      auto [idx, priority] = q.front();
      q.pop();
      if (-priority != pri.begin() -> first) q.push({idx, priority});
      else{
        count++;
        pri[-priority]--;
        if (!pri[-priority]) pri.erase(-priority);
        if (idx == target) {
          cout << count << "\n";
          break;
        }
      }
    }
  }
	return (0);
}

