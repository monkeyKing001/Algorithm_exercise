# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

### hypo 1. same problem with `1, 2, 3`

-> wrong. not just simple seq case count

### hypo 2. every seq starts W and ends H. So, just care only start and end char. the rest of middle seq is just every cases.

-> wrong. on seq index i, H count cannot exceed W count


# Approach
<!-- Describe your approach to solving the problem. -->

1. On seq index i, H count cannot exceed W count.

2. Think of how you can count exclude cases.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n^2) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n^2) $$

# Hint

<details>
<summary> <font size="4"> hint 1 </font> </summary>
<div markdown="1">

1. On seq index i, H count cannot exceed W count 

dp[w][h] means, how many cases are when we have w number of W, h number of H.

</div>
</details>

<details>
<summary> <font size="4"> hint 2 </font> </summary>
<div markdown="1">

Find Catalan number.

dp[w][h] means, how many cases are when we have w number of W, h number of H.

last char H or W cases will exclude each other.

</div>
</details>

# Tricky point

<details>
<summary> <font size="4"> Tricky point 1. when use Catalan number? </font> </summary>
<div markdown="1">

1. Dyck Words its total length is 2n  (문제와 같음)

e.g. Dyck words (XY 3 pair)C3 ⇒ XXXYYY XYXXYY XYXYXY XXYYXY XXYXYY

2. Change X, Y to '(', ')'. we can use Catalan number when finding the path on grid that doesn't exceed y = x inclination.

3. Number of combination for binary operation.

e.g. C3 ⇒ ((ab)c)d (a(bc))d (ab)(cd) a((bc)d) a(b(cd))

4. Number of full binary tree number.

![full_binary_tree](https://github.com/user-attachments/assets/53f4c8ac-b223-4a22-b508-dfc455df5d8c)

5. Finding the path on grid that doesn't exceed y = x inclination.

![grid_path](https://github.com/user-attachments/assets/231b569b-14d3-403c-acfd-741e3b74da79)

6. Drawing mountain

![Mountain](https://github.com/user-attachments/assets/7da5af0d-0ee0-4212-b1ee-20410a9312be)

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<vector<ll>> dp(31, vector<ll>(31, 0));
	dp[0][0] = 1;
	for (int i = 1; i < 31; i++){
		for (int j = 0; j <= i; j++) {
			if (j != 0)
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			else
				dp[i][j] = 1;
		}
	}
	int num;
	cin >> num;
	while (num != 0){
		cout << dp[num][num] << "\n";
		cin >> num;
	}
	return (0);
}

```

