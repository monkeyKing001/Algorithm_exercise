# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->



# Approach
<!-- Describe your approach to solving the problem. -->

1. visit every stairs.

2. optimization need with visit array.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Hint

<details>
<summary> <font size="4"> hint 1 </font> </summary>
<div markdown="1">

DFS

</div>
</details>

# Tricky point

<details>
<summary> <font size="4"> Tricky point 1. </font> </summary>
<div markdown="1">


</div>
</details>

# Trouble shooting

<details>
<summary> <font size="4"> Trouble 1. </font> </summary>
<div markdown="1">

0th floor doesn't exist.

</div>
</details>

# Code
```cpp []
#include <bits/stdc++.h>
using namespace std;

using info = pair<int, int>;
int n, m;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int F, S, G, U, D;
	int sol = -1;
	cin >> F >> S >> G >> U >> D;
	vector<int> d = {U, -D};
	vector<bool> visit(F + 1 , false);
	queue<info> q;
	visit[S] = 0;
	q.push({S, 0});
	while (q.size() != 0){
		auto [cur, cur_step] = q.front();
		q.pop();
		if (cur == G){
			sol = cur_step;
			break;
		}
		for (auto di : d){
			int next_stair = cur + di;
			int next_step = cur_step + 1;
			if (next_stair <= F && next_stair > 0 && !visit[next_stair]){
				visit[next_stair] = true;
				q.push({next_stair, next_step});
			}
		}
	}
	if (sol != -1) cout << sol;
	else cout << "use the stairs";
	return (0);
}

```

