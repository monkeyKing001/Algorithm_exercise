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

# Hint

<details>
<summary> <font size="4"> hint 1 </font> </summary>
<div markdown="1">

think three cases.
xo ox xx

</div>
</details>

# Tricky point


<details>
<summary> <font size="4"> Tricky point 1. minus result reason? </font> </summary>
<div markdown="1">

dp[i][case_j] = dp[i][case_j - 1] % mod - dp[i - 1][case_j] % mod -> minus

</div>
</details>

# Code
```cpp []
#include <bits/stdc++.h>
#define LION 1
#define NO_LION 0

using namespace std;
int n, m;
int mod = 9901;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> dp2(100001, 0);
	dp2[1] = 3;
	dp2[2] = 7;
	for (int i = 3; i < 100001; i++)
	{
			dp2[i] = 2 * dp2[i - 1] + dp2[i - 2];
			dp2[i] %= mod;
	}
	cout << dp2[n];
	return (0);
}


```

