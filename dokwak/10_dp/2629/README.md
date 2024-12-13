# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

1. brute force, backtracking
$$ O(2 ^ n) $$

2. priority_queue
$$ O(nlogn * n) $$


# Approach
<!-- Describe your approach to solving the problem. -->

1. count every possible case interating for a weight. there are 3 cases that can count on current iterating.


[1] dont choose

[2] putting on the right hand

[3] putting on the left hand (if minus, switch left, right side);

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n * 15000) = O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n * 15000) = O(n) $$

# Hint

<details>
<summary> <font size="4"> hint 1 </font> </summary>
<div markdown="1">

Counting every case doesn't mean brute force

$$ O(2^n) $$

can be reduce,

$$ O(n) $$

</div>
</details>


<details>
<summary> <font size="4"> hint 2 </font> </summary>
<div markdown="1">

in any chosen case, maximum possible weigth is limited in this problem 


</div>
</details>

<details>
<summary> <font size="4"> hint 3 </font> </summary>
<div markdown="1">

you can use vector<unordered_set<int>> or vector<vector<bool>> dp for count every case.
in any chosen case, maximum possible weigth is limited in this problem 


</div>
</details>

# Tricky point

<details>
<summary> <font size="4"> Tricky point 1. how can make new cases? </font> </summary>
<div markdown="1">

* no put -> prv_w
* put cur w on right side -> prv_w + w
* put cur w on left side -> prev_w - w (if it is less than 0, means change position. then abs(prev_w - cur_w) would do.)

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="4"> Trouble 1. </font> </summary>
<div markdown="1">

 contents

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>
#include <ctime>
#include <queue>
#include <vector>

using namespace std;
int n, m;
vector<vector<bool>> possible;
vector<unordered_set<int>> possible_set;

char sol(vector<int> &w, int target){
	if (possible_set[n].find(target) == possible_set[n].end())
		return ('N');
	return ('Y');
}

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	std::vector<int> weights(n , 0);
	for (int i = 0; i < n; i++) cin >> weights[i];
	cin >> m;
	std::vector<int> marbles(m, 0);
	for (int i = 0; i < m; i++) cin >> marbles[i];
	possible.resize(n + 1, vector<bool>(40001, false));
	possible_set.resize(n + 1);
	possible_set[0].insert(0);
	for (int i = 0; i < n; i++) {
		int cur_w = weights[i];
		for (auto case_ : possible_set[i]){
			possible_set[i + 1].insert(case_);
			possible_set[i + 1].insert(case_ + cur_w);
			possible_set[i + 1].insert(abs(case_ - cur_w));
		}
	}
	for (int i = 0; i < m; i++) cout << sol(weights, marbles[i]) << '\n';
	return (0);
}

```
``` java []

```

