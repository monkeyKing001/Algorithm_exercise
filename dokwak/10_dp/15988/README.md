# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
DP.
512MB memory is enough for 1000001 size of vec.

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
<summary> <font size="3"> Tricky point 1. what if count same combination as same case?  </font> </summary>
<div markdown="1">

Compare with BOJ problem num.15989

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. </font> </summary>
<div markdown="1">

 contents

</div>
</details>

# Code
```cpp []

#include <sys/resource.h>
#include <vector>
#include <iostream>
#include <cmath> 
#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;
int mod = 1000000009;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<ll> dp(1000001, 0);
  dp[0] = 1, dp[1] = 1, dp[2] = 2;
  for (int i = 3; i < dp.size(); i++){
    dp[i] = (dp[i - 1] % mod) + (dp[i - 2] % mod) + (dp[i - 3] % mod);
    dp[i] %= mod;
  }
  cin >> n;
  for (int t_i = 0; t_i < n; t_i++) {
    int num;
    cin >> num;
    cout << dp[num] << "\n";
  }
  return (0);
}

```

