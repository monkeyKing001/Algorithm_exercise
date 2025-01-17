#include <bits/stdc++.h>
#include <exception>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string buf;
  int count_num = 1;
  cin >> buf;
  if (buf.find("x") == string::npos){
    cout << 0;
    return (0);
  }
  string count_num_str = buf.substr(0, buf.find("x"));
  if (count_num_str.size() != 0 && count_num_str != "-")
    count_num = stoi(count_num_str);
  else if (count_num_str == "-")
    count_num = -1;
  cout << count_num;
  return (0);
}

