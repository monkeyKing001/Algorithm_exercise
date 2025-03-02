# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n^2) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n^2) $$

# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. does double for loop guarantee top down dp? </font> </summary>
<div markdown="1">

you can move only right or down. so current grid always from updated by previous left and upper grid box.

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. Memory limit exceed </font> </summary>
<div markdown="1">

queing for bfs solution occurs MLE. in worst case, queing can be occured in

pow(2, n ^ 2)

</div>
</details>

<details>
<summary> <font size="3"> Trouble 2. updating the very first visiting </font> </summary>
<div markdown="1">

wrong code :
```c++
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll cur_count = dp[i][j];
      ll step = grid[i][j];
      if (cur_count == -1 || (i == n - 1 && j == n - 1)) continue;
      for (int di = 0; di < 2; di++) {
        int next_r = i + (dr[di] * step);
        int next_c = j + (dc[di] * step);
        if (next_r < n && next_c < n){
                  //updating 1 is wrong. 
          if (dp[next_r][next_c] == -1) dp[next_r][next_c] = 1;
          else (dp[next_r][next_c] == -1) dp[next_r][next_c] += cur_count;
        }
      }
    }
  }

```

correct code :
```c++
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll cur_count = dp[i][j];
      ll step = grid[i][j];
      if (cur_count == -1 || (i == n - 1 && j == n - 1)) continue;
      for (int di = 0; di < 2; di++) {
        int next_r = i + (dr[di] * step);
        int next_c = j + (dc[di] * step);
        if (next_r < n && next_c < n){
          if (dp[next_r][next_c] == -1) dp[next_r][next_c] = 0;
          dp[next_r][next_c] += cur_count;
        }
      }
    }
  }
```

</div>
</details>

<details>
<summary> <font size="3"> Trouble 3. last grid box recursion </font> </summary>
<div markdown="1">

wrong code :
```c++

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll cur_count = dp[i][j];
      ll step = grid[i][j];
        // in last grid (n - 1, n - 1), the number is 0 and this will adding last dp recurrently
      if (cur_count == -1) continue;
      for (int di = 0; di < 2; di++) {
        int next_r = i + (dr[di] * step);
        int next_c = j + (dc[di] * step);
        if (next_r < n && next_c < n){
          if (dp[next_r][next_c] == -1) dp[next_r][next_c] = 0;
          dp[next_r][next_c] += cur_count;
        }
      }
    }
  }

```


correct code : 
``` 

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll cur_count = dp[i][j];
      ll step = grid[i][j];
      if (cur_count == -1 || (i == n - 1 && j == n - 1)) continue;
      for (int di = 0; di < 2; di++) {
        int next_r = i + (dr[di] * step);
        int next_c = j + (dc[di] * step);
        if (next_r < n && next_c < n){
          if (dp[next_r][next_c] == -1) dp[next_r][next_c] = 0;
          dp[next_r][next_c] += cur_count;
        }
      }
    }
  }

```

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>
#define ll long long

using namespace std;
int n, m;
int dr[2] = {1, 0};
int dc[2] = {0, 1};

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<vector<ll>> grid(n, vector<ll>(n, 0));
  vector<vector<ll>> dp(n, vector<ll>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll cur_count = dp[i][j];
      ll step = grid[i][j];
      if (!cur_count || (i == n - 1 && j == n - 1)) continue;
      for (int di = 0; di < 2; di++) {
        int next_r = i + (dr[di] * step);
        int next_c = j + (dc[di] * step);
        if (next_r < n && next_c < n) dp[next_r][next_c] += cur_count;
      }
    }
  }
  cout << dp[n - 1][n - 1];
  return (0);
}
```

