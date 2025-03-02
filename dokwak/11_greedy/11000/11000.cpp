#include <bits/stdc++.h>

using namespace std;
using info = pair<int, int>;
#define START first
#define END second
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<info> classes(n);
  for (int i = 0; i < n; i++) 
    cin >> classes[i].START >> classes[i].END;
  sort(classes.begin(), classes.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto &c : classes){
    auto [start, end] = c;
    if (pq.size() && pq.top() <= start)
      pq.pop();
    pq.push(end);
  }
  cout << pq.size();
  return (0);
}
