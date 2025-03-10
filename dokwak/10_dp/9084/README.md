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

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
  int coin_num, target_price;
	cin >> T;
  for (int t_i = 0; t_i < T; t_i++) {
    cin >> coin_num;
    vector<int> coins(coin_num, 0);
    for (int i = 0; i < coin_num; i++) cin >> coins[i];
    cin >> target_price;
    vector<int> dp(target_price + 1, 0);
    dp[0] = 1;
    for (auto coin : coins)
      for (int j = coin; j <= target_price; j++) dp[j] += dp[j - coin];
    cout << dp[target_price] << "\n";
  }
	return (0);
}


```

