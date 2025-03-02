#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  set<int> LIS;
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (LIS.size() == 0 || *LIS.rbegin() < num) LIS.insert(num);
    else{
      int pop_num = *LIS.lower_bound(num);
      LIS.erase(pop_num), LIS.insert(num);
    }
  }
  cout << LIS.size();

	return (0);
}

