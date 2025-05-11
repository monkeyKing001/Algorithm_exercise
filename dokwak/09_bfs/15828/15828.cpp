#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int max_buffer_size;
  cin >> max_buffer_size;
  queue<int> buffer;
  int info;
  cin >> info;
  while (info != -1){
    if (info && buffer.size() < max_buffer_size) buffer.push(info);
    else if (!info && buffer.size()) buffer.pop();
    cin >> info;
  }
  if (buffer.empty()){
    cout << "empty\n";
    return (0);
  }
  while(buffer.size()){
    cout << buffer.front() << " ";
    buffer.pop();
  }
  return (0);
}

