# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

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
<summary> <font size="3"> Trouble 1. pop when queue is not empty </font> </summary>
<div markdown="1">

before pop queue make sure pop size is not 0

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
  int max_buffer_size;
  cin >> max_buffer_size;
  queue<int> buffer;
  int info;
  cin >> info;
  while (info != -1){
    if (info && buffer.size() < max_buffer_size) buffer.push(info);
    else if (!info && buffer.size()) buffer.pop();
    cin >> info;
  }
  if (buffer.empty()){
    cout << "empty\n";
    return (0);
  }
  while(buffer.size()){
    cout << buffer.front() << " ";
    buffer.pop();
  }
  return (0);
}


```

