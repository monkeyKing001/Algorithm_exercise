# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

you can use binary serach in array or use set.

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(nlogn) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

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
  cin >> n;
  set<int> LIS;
  int num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (LIS.size() == 0 || *LIS.rbegin() < num) LIS.insert(num);
    else{
      int pop_num = *LIS.lower_bound(num);
      LIS.erase(pop_num), LIS.insert(num);
    }
  }
  cout << LIS.size();

	return (0);
}

```

