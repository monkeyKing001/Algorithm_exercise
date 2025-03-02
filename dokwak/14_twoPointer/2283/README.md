# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
Get all of zone's counts. iterate l, r with sliding window.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Hint

<details>
<summary> <font size="3"> hint 1 </font> </summary>
<div markdown="1">

 contents

</div>
</details>

# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. Expression for coordinate vs line with array </font> </summary>
<div markdown="1">

line for [0, 3] should be represent in array as below.
0--1--2--3

[0] [1] [2] [3]
 0   1   1   1

</div>
</details>

<details>
<summary> <font size="3"> Tricky point 2. sliding window, two pointer literating </font> </summary>
<div markdown="1">

when to move left and right and when to stop.

this can move window safely.
```
while (l <= r && l <= limit && r <= limit){

}
```
</div>
</details>


# Code
```cpp []
#include <bits/stdc++.h>
#define ll long long

using namespace std;
using line = pair<int, int>;
int n, m;
int limit = 1e6;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<line> lines(n);
  vector<int> prefix_sum(limit + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> lines[i].first >> lines[i].second;
    for (int j = lines[i].first + 1; j <= lines[i].second; j++) {
      prefix_sum[j]++;
    }
  }
  partial_sum(prefix_sum.begin(), prefix_sum.end(), prefix_sum.begin());
  //for (int i = 0; i < 21; i++)
  //  cout << prefix_sum[i] << " ";
  //cout << "\n";
  int l = 0, r = l;
  ll cur_sum = prefix_sum[r];
  while (l <= r && l <= limit && r <= limit){
    if (l == 0) cur_sum = prefix_sum[r];
    else cur_sum = prefix_sum[r] - prefix_sum[l];
    if (cur_sum == m) break;
    else if (cur_sum < m) r++;
    else if (cur_sum > m) l++;
  }
  if (cur_sum != m) l = 0, r = 0;
  cout << l << " " << r;
  return (0);
}


```

