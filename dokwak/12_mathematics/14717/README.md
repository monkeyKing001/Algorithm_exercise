# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
count all of the other case that can beat player's hands and cannot.
the total other case number must be 18C2

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(1) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(1) $$

# Hint

<details>
<summary> <font size="3"> hint 1 </font> </summary>
<div markdown="1">

Brute force

</div>
</details>

# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. how to implement 18C2 with double for loop? </font> </summary>
<div markdown="1">

this code count duplicate case {2, 3}, {3, 2}
```
for (int i = 1; i < 11; i++) {
  for (int j = 1; j < 11; j++) {

  }
}

```
this code count unique case < 2, 3 > do not count { 3, 2 }
```
for (int i = 1; i < 11; i++) {
  for (int j = i + 1; j < 11; j++) {

  }
}

```

</div>
</details>

<details>
<summary> <font size="3"> Tricky point 2. how to count combination case with unique hands? </font> </summary>
<div markdown="1">

use card count.
```
winning_count += (3 - card_count[i]) * (3 - card_count[j])
```

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. count fixed precision </font> </summary>
<div markdown="1">

```
cout << fixed;
cout.precision(3);
cout << winning_chance << "\n";
```

</div>
</details>

# Code
```cpp []
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
  vector<hands> total_hands(100);
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

```

