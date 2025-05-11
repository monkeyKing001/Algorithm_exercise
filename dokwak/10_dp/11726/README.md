# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
easy dp.
construct ignition.

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
#define ll long long

using namespace std;
int n, m;
int mod = 1e4 + 7;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  if (n == 1) {
    cout << 1;
    return (0);
  }
  vector<int> dp(n + 1, 0);
  dp[0] = 1; dp[1] = 1;
  for (int i = 2; i <= n; i++){
    dp[i] += dp[i - 1] + dp[i - 2];
    dp[i] %= mod;
  }
  cout << dp[n];
  return (0);
}


```

