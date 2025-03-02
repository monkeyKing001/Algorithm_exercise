# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

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
<summary> <font size="3"> Tricky point 1. What if considering same combination and different order is duplicate??   </font> </summary>
<div markdown="1">

Compare with BOJ problem no.15989

</div>
</details>

# Code
```cpp []
#include <bits/stdc++.h>
using namespace std;
int n;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int T = n;
  vector <int> dp(11, 0);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = (dp[1] + (dp[0] + 1));  //2
  dp[3] = (dp[2] + dp[1] + dp[0] + 1); //4
  for (int i = 4; i < 11; i++) 
    dp[i] = dp[i- 1] + dp[i - 2] + dp[i - 3];  
  for (int t_i = 0; t_i < T; t_i++) {
    int num;
    cin >> num;
    cout << dp[num] << "\n";
  }
	return (0);
}


```

