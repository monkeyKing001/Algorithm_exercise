# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

1. use dp array dp[10001][last_num_digit]

-> wrong : 
this count duplicate case
```c++
for (int i = 4; i < 10001; i++){
	for (int j = 1; j <= 3; j++) {
		dp[i][j] = dp[i - j][1] + dp[i - j][2] + dp[i - j][3];
	}
```
Example

1 : 1 (1)

2 : 2 (1 + 1, 2)

3 : 3 (1 + 1 + 1, 1 + 2, 3)

4 : 4 (1 + 1 + 1 + 1, 1 + 1 + 2, 2 + 2, 1 + 3)


# Approach
<!-- Describe your approach to solving the problem. -->

1. it is clearly sure that you have to use previous infomation to make current case.

2. let's make every sequence as weak increasing

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

$$ O(n) $$


- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

$$ O(n) $$


# Hint

<details>
<summary> <font size="4"> hint 1 </font> </summary>
<div markdown="1">

how make an seq increasing? what is feature of weak increasing seq?

</div>
</details>

<details>
<summary> <font size="4"> hint 2 </font> </summary>
<div markdown="1">

memo the case count by last digit

</div>
</details>

# Tricky point

<details>
<summary> <font size="4"> Tricky point 1. ?  </font> </summary>
<div markdown="1">

 contents

</div>
</details>

# Trouble shooting

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
	cin >> T;
	vector<vector<int>> dp(10001, vector<int>(4, 0));
	dp[1][1] = 1;
	dp[2][1] = 1, dp[2][2] = 1;
	dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;
	for (int i = 4; i < 10001; i++){
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= j; k++){
				dp[i][j] += dp[i - j][k];
			}
		}
	}
	for (int t_i = 0; t_i < T; t_i++) {
		int num;
		cin >> num;
		cout << dp[num][1] + dp[num][2] + dp[num][3] << "\n";
	}
	return (0);
}

```

