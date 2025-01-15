# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
Implement round function.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. from idx 0 to n - 1? or from n - 1 to 0</font> </summary>
<div markdown="1">

from 0 to n - 1 is better.

</div>
</details>

<details>
<summary> <font size="3"> Tricky point 2. be careful for rounding up for index 0 </font> </summary>
<div markdown="1">

push_front 1 or make the digit int to 10

</div>
</details>

# Code
```cpp []
#include <bits/stdc++.h>

using namespace std;
int n, m;

void roundUp(deque<int> &deq, int idx){
  for (int i = idx; i < deq.size(); i++) deq[i] = 0;
  if (idx == 0) deq.push_front(1);
  else deq[idx - 1]++;
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  deque<int> buf;
  string input;
  cin >> input;
  for (auto i : input)
    buf.push_back(i - '0');
  bool optimized = false;
  while (!optimized){
    for (int i = 0 ; i <= buf.size(); i++){
      if (buf[i] >= 5){
        roundUp(buf, i);
        break;
      }
      if (i == buf.size() - 1)
        optimized = true;
    }
  }
  for (auto i : buf) cout << i;
  return (0);
}

```

