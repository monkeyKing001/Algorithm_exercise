# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
count all of x, y point freq.
and if there are over 2 freq of point postion, there is a line.

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

if two point has same x or y, it will make a line that parallel for x or y axis. 

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>
#define POS first
#define COUNT second
using namespace std;
using point = pair<int, int>;
int n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  unordered_map<int, int> x_count;
  unordered_map<int, int> y_count;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x_count[x]++;
    y_count[y]++;
  }
  int ans = 0;
  for (auto x_info : x_count){
    if (x_info.COUNT >= 2) ans++;
  }
  for (auto y_info : y_count){
    if (y_info.COUNT >= 2)
      ans++;
  }
  cout << ans;
  return (0);
}


```

