# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

first approach : naive bfs. -> MLE

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. Why can't use q? </font> </summary>
<div markdown="1">

unoptimized q occurs memory limit exceed 

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. MLE </font> </summary>
<div markdown="1">

naive bfs solution is MLE.

</div>
</details>

# Code
```cpp [] v1. BFS + DP

#include <bits/stdc++.h>

using namespace std;
int n;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n; 
  vector <int> nums(n + 1, INT_MAX);
  queue<pair<int, int>>q;
  q.push({1, 0});
  nums[1] = 0;
  while (q.size() && nums[n] == INT_MAX){
    auto [num, steps] = q.front();
    q.pop();
    for (int i = 0; i < 3; i++) {
      int next_num = num + 1;
      if (i == 1) next_num = num * 2;
      if (i == 2) next_num = num * 3;
      if (next_num <= n && nums[next_num] == INT_MAX) {
        nums[next_num] = steps + 1;
        q.push({next_num, steps + 1});
      }    
    }
  }
  cout << nums[n];
	return (0);
}

```

```cpp [] v2. for loop bottom up

#include <bits/stdc++.h>

using namespace std;
int n;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  int sol = 0;
  cin.tie(0);
  cin >> n; 
  vector<int> v(n + 1, INT_MAX);
  v[1] = 0;
  for (int i = 1; i < n + 1; i++) {
    if (v[i] != INT_MAX){
      for (int j = 0; j < 3; j++) {
        int next_num = i + 1;
        if (j == 1) next_num = i * 2;
        if (j == 2) next_num = i * 3;
        if (next_num > n) break;
        v[next_num] = min(v[next_num], v[i] + 1);
      }
    }
  }
  cout << v[n];
	return (0);
}

```
