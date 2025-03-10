# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

brute force + backtracking.

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(mCn) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Hint

<details>
<summary> <font size="3"> hint 1. brute force  </font> </summary>
<div markdown="1">

brute force for every case and after then check if that string is good to print.


</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. INF Loop </font> </summary>
<div markdown="1">

error on inputs + and -;


</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 2. need two idx. </font> </summary>
<div markdown="1">

one for buf idx and another for previous alphabet idx.

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>

using namespace std;
int n, m;
unordered_set<char> mo_set = {'a', 'e', 'i' ,'o', 'u'};
vector<int> inputs(26, 0);

bool good(string &buf){
  int mo_count = 0, ja_count = 0;
  for (int i = 0; i < buf.size(); i++){
    if (mo_set.find(buf[i]) != mo_set.end()) mo_count++;
    else ja_count++;
  }
  return (mo_count >= 1 && ja_count >= 2);
}

void rec(int idx, int prev_char, string &buf){
  if (idx == n && good(buf)){
    cout << buf << "\n"; return ;
  }
  for (int i = prev_char + 1; i < 26; i++){
    if (inputs[i]){
      inputs[i]--;
      buf.push_back('a' + i);
      rec(idx + 1, i ,buf);
      inputs[i]++;
      buf.pop_back();
    }
  }
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  string buf;
  buf.reserve(n);
  for (int i = 0; i < m; i++) {
    char chr;
    cin >> chr;
    inputs[chr - 'a']++;
  }
  rec(0, -1, buf);
  return (0);
}

```

