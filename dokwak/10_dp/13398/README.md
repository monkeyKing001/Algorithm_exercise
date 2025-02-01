# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
We can make subarray in 2 different way. 1) start from index i or 2) coninuous subarray that made before. the problem is how to exclude a number that make subarray sum makes maximum.

we can try in bruteForce way or use memoization.


# Approach
<!-- Describe your approach to solving the problem. -->

if cuurent i's number is less than 0, we can use the chance to exclude current number or save the chance. following that rule, we can make memoization array.

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

make `vector<vector<int>> dp(2, vector<int>(n, 0));` this is kind of tree dp.
dp[1][i] means, when we have 1 chance to exclude, the maximum sum of subarray.
dp[0][i] means, when we have no chance.

dp[0][i] can be made 1) conituous from previous optimum case, 2) make new subarray with current number or 3) use one chance to exclude current number.


</div>
</details>

<details>
<summary> <font size="3"> hint 2 </font> </summary>
<div markdown="1">

make `vector<vector<int>> dp(2, vector<int>(n, 0));` this is kind of tree dp.

</div>
</details>


# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. how can decide optimum `dp[0][i]` </font> </summary>
<div markdown="1">

```
dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]); //make conituous subarr, or start new subarray. if current subarray prefix sum becomes less than current number, we have to start new subarray.
dp[0][i] = max(dp[0][i], dp[1][i - 1]); //or use chance to exclude.

```


</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. when given an array that contains only numbers less than 0 </font> </summary>
<div markdown="1">


</div>
</details>


<details>
<summary> <font size="3"> Trouble 2. we have to choose at least one number. </font> </summary>
<div markdown="1">

`dp[0][0]` cannot be 0. we have to exclude that case. make `dp[0][0]` as minumum value.


</div>
</details>

# Code
```cpp []
#include <bits/stdc++.h>

using namespace std;
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> arr(n);
  int ans = INT_MIN;
  vector<vector<int>> dp(2, vector<int>(n, 0));
  for (int i = 0; i < n; i++) 
    cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (i > 0){
      dp[1][i] = max(dp[1][i - 1] + arr[i], arr[i]);
      dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]);
      dp[0][i] = max(dp[0][i], dp[1][i - 1]);
    }
    else{
      dp[1][i] = arr[i];
      dp[0][i] = -1 * 1e9;
    }
    ans = max(ans, dp[1][i]);
    ans = max(ans, dp[0][i]);
  }
  cout << ans;
  return (0);
}


```

