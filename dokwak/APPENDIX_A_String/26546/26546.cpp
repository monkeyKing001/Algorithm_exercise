#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
  for (int t_i = 0; t_i < T; t_i++) {
    string buf;
    string output;
    int start, end;
    cin >> buf >> start >> end;
    output.reserve(buf.size());
    for (int i = 0; i < buf.size(); i++) 
      if (i < start || i >= end) output.push_back(buf[i]);
    cout << output << "\n";
  }
	return (0);
}

