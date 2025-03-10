#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string buf;
  string rpl;
	unordered_set<string> cro = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	vector<string> croatian(cro.begin(), cro.end());
	cin >> buf;
  rpl = buf;
	int num = buf.size();
  int i = -1;
  int cro_size = 0;
  int sol = 0;
  while (++i < buf.size()){
    for (auto c : cro){
      if (buf.compare(i, c.size(), c) == 0){
        //cout << "found in i, c : " << i << ", " << c << "\n";
        i+= c.size() - 1;
        cro_size += c.size() - 1;
      }
    }
  }
  sol = buf.size() - cro_size;
	cout << sol;
	return (0);
}

