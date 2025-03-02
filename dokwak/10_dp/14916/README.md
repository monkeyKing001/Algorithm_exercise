# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Code
```cpp []

#include <bits/stdc++.h>

using namespace std;
int n, m;
int max_cost = 1e7 + 7;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int ans = max_cost;
  vector<int> dp(n + 1, max_cost);
  if (n >= 5){
    dp[2] = dp[5] = 1, dp[4] = 2; 
    for (int i = 6; i < n + 1; i++) {
      dp[i] = min(dp[i], dp[i - 5] + 1);
      dp[i] = min(dp[i], dp[i - 2] + 1);
    }
    ans = dp[n];
  }
  else
    ans = (n % 2 == 0) ? n / 2 : max_cost;
  ans = ans == max_cost ? -1 : ans; 
  cout << ans;
  return (0);
}


```

