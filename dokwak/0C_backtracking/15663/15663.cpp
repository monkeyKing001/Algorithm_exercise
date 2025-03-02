#include <bits/stdc++.h>

using namespace std;
int n, m;


void rec(int idx, map<int, int> &num_count, vector<int> &buffer){
  if (idx == m){
    for (auto b: buffer) cout << b << " "; 
    cout << "\n";
    return;
  }
  for (auto &[num, count] : num_count){
    if (!count) continue;
    buffer[idx] = num;
    count--;
    rec(idx + 1, num_count, buffer);
    buffer[idx] = -1;
    count++;
  }
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m;
  map<int, int> num_count;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    num_count[num]++;
  }
  vector<int> buffer(m, -1);
  rec(0, num_count, buffer);
	return (0);
}

