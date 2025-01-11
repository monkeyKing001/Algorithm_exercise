#include <bits/stdc++.h>

using namespace std;
using hands = pair<int, int>;

int n, m;

bool cmp (hands h1 , hands h2){
  int h1_score = 0, h2_score = 0;
  if (h1.first == h1.second)
    h1_score = h1.first * h1.first * 100;
  if (h2.first == h2.second)
    h2_score = h2.first * h2.first * 100;
  if (!h1_score)
    h1_score = (h1.first + h1.second) % 10;
  if (!h2_score)
    h2_score = (h2.first + h2.second) % 10;
  return (h1_score < h2_score);
}

int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int count = 0;
  cin >> n >> m;
  int not_winning_count = 0;
  int winning_count = 0;
  vector<int> card_count(11, 0);
  card_count[n]++, card_count[m]++;
  for (int i = 1; i < 11; i++) {
    for (int j = i; j < 11; j++) {
      card_count[i]++, card_count[j]++;
      if (card_count[n] < 3 && card_count[m] < 3) {
        if (cmp({i, j}, {n, m})) winning_count += (3 - card_count[i]) * (3 - card_count[j]);
        else not_winning_count += (3 - card_count[i]) * (3 - card_count[j]);
      }
      card_count[i]--, card_count[j]--;
    }
  }
  double winning_chance = (double)winning_count / (double)(winning_count + not_winning_count);
  cout << fixed;
  cout.precision(3);
  cout << winning_chance << "\n";
  return (0);
}

