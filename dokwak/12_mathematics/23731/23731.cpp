#include <bits/stdc++.h>

using namespace std;
int n, m;

void roundUp(vector<int> &deq, int idx){
  for (int i = idx; i < deq.size(); i++) deq[i] = 0;
  if (idx == 0) deq[idx] = 10;
  else deq[idx - 1]++;
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string input;
  cin >> input;
  vector<int> buf(input.size(), 0);
  for (int i = 0; i < input.size(); i++) 
    buf[i] = input[i] - '0';
  bool optimized = false;
  while (!optimized){
    for (int i = 0 ; i < buf.size(); i++){
      if (buf[i] >= 5){
        if (i == 0 && buf[i] == 10){
          optimized = true;
          break;
        }
        roundUp(buf, i);
        break;
      }
      if (i == buf.size() - 1)
        optimized = true;
    }
  }
  for (auto i : buf) cout << i;
  return (0);
}

