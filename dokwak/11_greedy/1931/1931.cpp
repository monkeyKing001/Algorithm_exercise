#include <bits/stdc++.h>

#define START first
#define END second

using namespace std;
using info = pair<int, int>;
int n;

bool cmp (info i1 ,info i2){
  if (i1.END== i2. END) 
    return (i1.START < i2.START);
  return (i1.END < i2.END);
}

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector <info> time_table(n);
  int class_num = 0;
  for (int i = 0; i < n; i++)
    cin >> time_table[i].START >> time_table[i].END;
  sort(time_table.begin(), time_table.end(), cmp);
  int last_end = 0;
  for (auto &t: time_table){
    if (t.START < last_end)
      continue;
//    cout
//      << "next class start, end : " 
//      << t.START
//      << ", "
//      << t.END
//      << "\n";
    last_end = t.END;
    class_num++;
  }
  cout << class_num;
	return (0);
}
