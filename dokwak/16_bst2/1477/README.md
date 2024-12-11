# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
first thoughts 
1. use pq ordered by longest distance btw stations.

2. try minimum max interval with binary search.

# Approach
<!-- Describe your approach to solving the problem. -->
Priority queue doesn't work. spliting longest distance in half doesn't guarantee the optimal solution.

use.

* binary search
* parametric search

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(n +logn) = O(nlogn) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
 $$ O(n) $$ 

# Hint

<details>
<summary> <font size="4"> hint 1 </font> </summary>
<div markdown="1">

sort given stations first.

</div>
</details>

<details>
<summary> <font size="4"> hint 2 </font> </summary>
<div markdown="1">

try minimum biggest interval for every station[i] - station[i + 1]

</div>
</details>

# Tricky point

<details>
<summary> <font size="4"> Tricky point 1. why cannot use priority_queue? </font> </summary>
<div markdown="1">

Q. Why cannot use priority queue that ordered by lenth btw statinos and cut in half?

A. Let's suppose spliting 9 len with two stations. pq way will make 4.5, 4.5 -> 4.5, 2.25, 2.25. but 6, 3 -> 3, 3, 3 is better way.

</div>
</details>


<details>
<summary> <font size="4"> Tricky point 2. how can split the len within given interval? </font> </summary>
<div markdown="1">

```c++
bool possible(vector<int> &stations, int interval){
	int prv_station = 0;
	int more_stations = m;
	for (auto s: stations){
		while (s - prv_station > interval && more_stations > 0) prv_station += interval, more_stations--;
		if (s - prv_station > interval) return false;
		prv_station = s;
	}
	return true;
} 

```

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

using namespace std;
int n, m, max_len;
bool possible(vector<int> &stations, int interval){
	int prv_station = 0;
	int more_stations = m;
	for (auto s: stations){
		while (s - prv_station > interval && more_stations > 0) prv_station += interval, more_stations--;
		if (s - prv_station > interval) return false;
		prv_station = s;
	}
	return true;
} 

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> max_len;
	vector<int> stations(n + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> stations[i];
	stations.back() = max_len;
	sort(stations.begin(), stations.end());
	int l = 1, r = max_len;
	int sol = INT_MAX;
	while (l <= r){
		int mid = (l + r) / 2;
		if (possible(stations, mid))
			r = mid - 1, sol = mid;
		else
			l = mid + 1;
	}
	cout << sol;
	return (0);
}

```

