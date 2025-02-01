# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
with the given i day's data, we can expect the start prize in i + cost_day's day. 
so, use memoization.

# Approach
<!-- Describe your approach to solving the problem. -->
Dynamic programming.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. How to decide optimal prize start? </font> </summary>
<div markdown="1">

1) On i's day, get the best start prize data from the past.
```
if (i > 0)
  dp[i] = max(dp[i - 1], dp[i]);
```

2) We can calculate i + cost_day's start prize, and this can be modify by other case. so, update with `max(a, b)`
```
if (target_day <= n + 1)
  dp[target_day] = max(dp[target_day], prize + start_prize);
```

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. dp indexing error </font> </summary>
<div markdown="1">

Solved : Fix the meaning of index as day.

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>
using namespace std;
using info = pair<int, int>;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> dp(n + 2, 0);
  vector<info> infos(n + 1);
  for (int i = 1; i < n + 1; i++)
    cin >> infos[i].first >> infos[i].second;
  int ans = 0;
  for (int i = 1; i <= n; i++){
    auto [cost_time, prize] = infos[i];
    if (i > 0)
      dp[i] = max(dp[i - 1], dp[i]);
    int start_prize = dp[i];
    int target_day = i + cost_time;
    if (target_day <= n + 1)
      dp[target_day] = max(dp[target_day], prize + start_prize);
  }
  dp[n + 1] = max(dp[n + 1], dp[n]);
  cout << dp.back();
  return (0);
}


```

