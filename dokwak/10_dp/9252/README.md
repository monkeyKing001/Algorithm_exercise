# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

#ex1. 
 0ACAYKP
10000000
C0011111
A0112222
P0112223
C0122223
A0123333
K0123344

# Approach
<!-- Describe your approach to solving the problem. -->
attach 0, 1 for each str1, str2
2D dp

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n * m) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n * m) $$

# Hint

<details>
<summary> <font size="3"> hint 1 </font> </summary>
<div markdown="1">

 contents

</div>
</details>

# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. Why attach 0, 1 to str1, str2 </font> </summary>
<div markdown="1">

for conveniences when iterating 2d DP
```
if (input1[j] == input2[i]) dp[i][j] = dp[i - 1][j - 1] + 1;
```

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
#include <bits/stdc++.h>

using namespace std;
int n, m;
int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string input1, input2;
  cin >> input1 >> input2;
	input1 = "0" + input1;
	input2 = "1" + input2;
  vector<vector<int>> dp(input2.size(), vector<int>(input1.size()));
  for (int i = 0; i < input2.size(); i++) {
    for (int j = 0; j < input1.size(); j++) {
      if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      if (input1[j] == input2[i]) dp[i][j] = dp[i - 1][j - 1] + 1;
    }
  }
  string LCS = "";
  cout << dp.back().back() << "\n";
  int i = input1.size() - 1, j = input2.size() - 1; 
  while (i >= 0 && j >= 0){
    if (input1[i] != input2[j]){
      if (i > 0 && dp[j][i] == dp[j][i - 1]) i--;
      else j--;
    }
    else LCS.push_back(max(input1[i--], input2[j--]));
  }
  string sol(LCS.rbegin(), LCS.rend());
  cout << sol;
	return (0);
}


```

