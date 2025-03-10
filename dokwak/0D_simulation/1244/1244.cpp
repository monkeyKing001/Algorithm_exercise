#include <bits/stdc++.h>
#define MALE 1
#define FEMALE 2

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> switches_(n + 1, 0);
  for (int i = 0; i < n; i++) cin >> switches_[i + 1];
  cin >> m;
  vector<pair<int, int>> act(m);
  for (int i = 0; i < m; i++) cin >> act[i].first >> act[i].second;
  for (auto a: act){
    auto [gender, num] = a;
    if (gender == MALE){
      for (int i = num; i <= n; i+= num) switches_[i] = (switches_[i] != 1);
      //cout << "MALE!\n";
      //for (int i = 1; i <= n; i++){
      //  cout << switches_[i] << " ";
      //  if (i % 20 == 0) cout << "\n";
      //}
      //cout << "\n";
    }
    else {
      int l = num - 1, r = num + 1;
      switches_[num] = switches_[num] != 1; 
      while (l >= 1 && r <= n){
        if (switches_[l] == switches_[r]){
          switches_[l] = switches_[l] != 1; 
          switches_[r++] = switches_[l--];
        }
        else break;
      }
      //cout << "FEMALE!\n";
      //for (int i = 1; i <= n; i++){
      //  cout << switches_[i] << " ";
      //  if (i % 20 == 0) cout << "\n";
      //}
      //cout << "\n";
    }
  }
  for (int i = 1; i <= n; i++){
    cout << switches_[i] << " ";
    if (i % 20 == 0) cout << "\n";
  }
  cout << "\n";
  return (0);
}

