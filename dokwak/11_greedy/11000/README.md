# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
sort class with start time and enque in pq by end time.

# Approach
<!-- Describe your approach to solving the problem. -->

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

 contents

</div>
</details>

# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. </font> </summary>
<div markdown="1">

 contents

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. not working poping </font> </summary>
<div markdown="1">

wrong
```
  priority_queue<int> pq;
```

correct
```
  priority_queue<int, vector<int>, greater<int>> pq;
```

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>

using namespace std;
using info = pair<int, int>;
#define START first
#define END second
int n, m;

int main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<info> classes(n);
  for (int i = 0; i < n; i++) 
    cin >> classes[i].START >> classes[i].END;
  sort(classes.begin(), classes.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto &c : classes){
    auto [start, end] = c;
    if (pq.size() && pq.top() <= start)
      pq.pop();
    pq.push(end);
  }
  cout << pq.size();
  return (0);
}
```

