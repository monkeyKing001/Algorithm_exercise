# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
same with leetcode not overlapping maximum 3 subarray.

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

need left dp, right dp, dp.

</div>
</details>

# Tricky point

<details>
<summary> <font size="4"> Tricky point 1. </font> </summary>
<div markdown="1">

check correctly left idx, right idx, now idx 

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="4"> Trouble 1. when m = 1, idx can be out of range </font> </summary>
<div markdown="1">

fixed with
```c++
	if (i + 1 <= n - 1)
		dp_right[i] = max(dp_right[i], dp_right[i + 1]);
```

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
	vector<int> dp_left(1, 0);
	vector<int> dp_right(1, 0);
	vector<int> dp(1, 0);
	vector<int> info(1, 0);
	cin >> n;
	info.resize(n, 0);
	dp_left.resize(n, 0);
	dp_right.resize(n, 0);
	dp.resize(n, 0);
	int sum = 0;
	for (int i = 0; i < n; i++) 
		cin >> info[i];
	cin >> m;
	sum = 0;
	for (int i = 0; i < n; i++){
		sum += info[i];
		dp[i] = sum;
		dp_left[i] = sum;
		if (i - 1 >= 0)
			dp_left[i] = max(dp_left[i], dp_left[i - 1]);
		if (i - (m - 1) >= 0)
			sum -= info[i - (m - 1)];
	}
	sum = 0;
	for (int i = n - 1; i >= 0; i--){
		sum += info[i];
		dp_right[i] = sum;
		if (i + 1 <= n - 1)
			dp_right[i] = max(dp_right[i], dp_right[i + 1]);
		if (i + m - 1 <= n - 1)
			sum -= info[i + m - 1];
	}
	int ans = 0;
	for (int i = (2 * m) - 1; i + 1 <= n - 1 - (m - 1); i++){
		int left_idx = i - m;
		int right_idx = i + 1;
		ans = max(ans, dp[i] + dp_left[left_idx] + dp_right[right_idx]);
	}
	cout << ans;
	return (0);
}
```

