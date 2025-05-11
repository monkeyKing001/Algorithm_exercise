# Mistakes and Advice
<!-- Describe your first thoughts on how to solve this problem. -->

Do not use increment in condition check(if or while etc...).
It occurs many errors.

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

1 2 3 2 5 6
3 8 7 2 1 3
8 2 3 1 4 5
3 4 5 1 1 1
9 3 2 1 4 3
3 4 2

1 8 2 3 2 5
3 2 3 7 2 6
8 4 5 1 1 3
3 3 1 1 4 5
9 2 1 4 3 1

# Approach
<!-- Describe your approach to solving the problem. -->
Do not use

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Hint

<details>
<summary> <font size="3"> hint 1. next_permutation </font> </summary>
<div markdown="1">

return value is false when no other permutation exist

</div>
</details>

# Tricky point

<details>
<summary> <font size="3"> Tricky point 1. when to pass value or reference </font> </summary>
<div markdown="1">



</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. Infinite loop </font> </summary>
<div markdown="1">

wrong :
```c++
  } while(r != start_r && c != start_c); //if ( r = sr or c = sc) break. is that really my intention?
```

correct :
```c++
  } while(r != start_r || c != start_c); //keep if (any of r, c is not start point)
```
* becareful not to confuse stop condition or continue condition


</div>
</details>

<details>
<summary> <font size="3"> Trouble 2. min = 0 </font> </summary>
<div markdown="1">
        
array size was n + 1, m + 1 and init with 0 
for (auto &rows) will itereate 0 0 0 0 ... row

</div>
</details>

<details>
<summary> <font size="3"> Trouble 3. garbage value </font> </summary>
<div markdown="1">


</div>
</details>

<details>
<summary> <font size="3"> Trouble 4. off-by-one error -> false direction change </font> </summary>
<div markdown="1">

wrong:
```c++

  int cur_move = 1;
  do{
    if (cur_move++ == move_count){
      cur_move = 1;
      di++;
    }
```

correct 1 :
```c++
  int cur_move = 1;
  do{
    if (cur_move == move_count){
      cur_move = 1;
      di++;
    }
  cur_move++;

```

correct 2 :
```c++

  int cur_move = 0;
  do{
    if (++cur_move == move_count){
      di++;
      cur_move = 1;
    }

```

correct 3 :
```c++
  do{
    if (cur_move++ == move_count){
      di++;
      cur_move = 1;
      continue;
    }
```

correct 4 :
```c++
  do{
    if (cur_move++ == move_count){
      di++;
      cur_move = 1;
      cur_move++;
    }
```

diff : wrong code do not stop when initializing cur_move condition.

</div>
</details>

<details>
<summary> <font size="3"> Trouble 5.  </font> </summary>
<div markdown="1">

 contents

</div>
</details>

# Code

```cpp []
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using rot_info = tuple<int, int, int>;
int n, m, k;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int sol = INT_MAX;

void cal(vector<vector<int>> &arr){
  for (int i = 1; i < n + 1; i++) {
    auto &rows = arr[i];
    partial_sum(rows.begin(), rows.end(), rows.begin());
    sol = min(sol, rows.back());
  }
}

void rotate_clockwise_recur(vector<vector<int>> &arr, rot_info info){
  auto &[center_r, center_c, s] = info;
  if (s == 0) return;
  int start_r = center_r - s, start_c = center_c - s;
  int r = start_r, c = start_c;
  int pop_num = arr[r][c], next_pop_num = arr[r][c];
  int di = 0;
  int move_count = (s * 2) + 1;
  int cur_move = 1;
  do{
    if (cur_move++ == move_count){
      di++;
      cur_move = 1;
      continue;
    }
    int next_r = r + dr[di], next_c = c + dc[di];
    next_pop_num = arr[next_r][next_c];
    arr[next_r][next_c] = pop_num;
    pop_num = next_pop_num;
    r = next_r; c = next_c;
  } while(r != start_r || c != start_c);
  s--;
  rotate_clockwise_recur(arr, info);
}

void rotate_with_info(vector<vector<int>> &arr, vector<rot_info> rots, int idx){
  rotate_clockwise_recur(arr, rots[idx]);
}

void rotate(vector<vector<int>> &arr, vector<rot_info> rots, vector<int> &order){
  for (auto idx : order) rotate_with_info(arr, rots, idx);
//  for (int i = 1; i < n + 1; i++) {
//    for (int j = 1; j < m + 1; j++){
//      cout << arr[i][j] << " ";
//    }
//    cout << "\n";
//  }
//  cout << "\nafter cal\n";
  cal(arr);
//  for (int i = 1; i < n + 1; i++) {
//    for (int j = 1; j < m + 1; j++){
//      cout << arr[i][j] << " ";
//    }
//    cout << "\n";
//  }
//  cout << "\n";
}

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i < n + 1; i++) 
    for (int j = 1; j < m + 1; j++) cin >> arr[i][j];
  vector<int> rot_order(k, 0);
  vector<rot_info> rotations(k);
  for (int i = 0; i < k; i++) {
    int r, c, s;
    cin >> r >> c >> s;
    rotations[i] = {r, c, s};
    rot_order[i] = i;
  }
  do{
    auto cp = arr;
    rotate(cp, rotations, rot_order);
  } while(next_permutation(rot_order.begin(), rot_order.end()));
  cout << sol;
  return (0);
}


```

