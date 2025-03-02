# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
1 : 1
2 : 10 
3 : 101, 100
4 : 1010, 1000, 1001
5 : 10100, 10101, 10000, 10001, 10010


# Approach
<!-- Describe your approach to solving the problem. -->
Append 0 or 1 from last seq, and we can append 1 only when the last seq ends with 0. 

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

make 2d dp array that represents length and end number.

</div>
</details>


# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. case when n = 90 </font> </summary>
<div markdown="1">

integer overflow error

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<vector<ll>> dp(n + 1, vector<ll> (2, 0));
  dp[1][1] = 1;
  for (int i = 2; i < n + 1; i++){
    dp[i][0] += dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] += dp[i - 1][0];
  }
  cout << dp[n][0] + dp[n][1];

  return (0);
}
```

