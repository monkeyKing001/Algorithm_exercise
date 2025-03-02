#include <bits/stdc++.h>

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  n = 20;
  unordered_map<string, double> table = {
    {"A+", 4.5},
    {"A0", 4.0},
    {"B+", 3.5},
    {"B0", 3.0},
    {"C+", 2.5},
    {"C0", 2.0},
    {"D+", 1.5},
    {"D0", 1.0},
    {"P", 0.0},
    {"F", 0.0}
  };
  double total_credits = 0.0;
  double total_score = 0.0;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    string name, grade;
    double credits;
    cin >> name >> credits >> grade;
    if (grade != "P"){
      total_score += (credits * table[grade]);
      total_credits += credits;
    }
  }
  cout << setprecision(7);
  if (total_credits != 0) cout << total_score / total_credits;
  else cout << "0.000000";
  return (0);
}

