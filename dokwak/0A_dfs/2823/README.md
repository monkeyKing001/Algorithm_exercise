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
<summary> <font size="3"> Tricky point 1. how dead end guarantees acycle. </font> </summary>
<div markdown="1">

 contents

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. </font> </summary>
<div markdown="1">

 contents

</div>
</details>

# Code
```cpp []
#include<iostream>
#define f(a,b) for(int a=0;a<b;++a)
 
using namespace std;
int R, C,cnt;
int d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
string s[10];
 
bool canMove(int i, int j) {
    if (i == -1 || j == -1 || i == R || j == C|| s[i][j] == 'X')return false;
    return true;
}
 
bool solve() {
    f(i, R)f(j, C)if(s[i][j]=='.') {
        int cnt=0;
        f(k, 4)if (canMove(i + d[k][0], j + d[k][1]))++cnt;
        if (cnt == 1)return false;
    }
    return true;
}
 
int main() {
    cin >> R >> C;
    f(i, R)cin >> s[i];
    cout << (solve() ? 0 : 1)<<endl;
}

```

