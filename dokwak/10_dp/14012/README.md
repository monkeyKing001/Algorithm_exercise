# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->


# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(nlogn) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Hint

<details>
<summary> <font size="3"> hint 1 </font> </summary>
<div markdown="1">

Greedy Algorithm.

</div>
</details>

<details>
<summary> <font size="3"> hint 2 </font> </summary>
<div markdown="1">

Greedy Algorithm.

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="3"> Trouble 1. Integer overflow </font> </summary>
<div markdown="1">

integer overflow occured

</div>
</details>

# Code
```cpp []

#include <bits/stdc++.h>
#define ll long long
#define COST first
#define PAYOFF second

using namespace std;
using info = pair<ll, ll>;
ll n, m;

int	main(int argc, char **argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<info> infos(n);
  for (int i = 0; i < n; i++) 
    cin >> infos[i].COST;
  for (int i = 0; i < n; i++) 
    cin >> infos[i].PAYOFF;
  sort(infos.begin(), infos.end());
  for (auto i : infos){
    auto [cost, payoff] = i;
    if (cost > m)
      break;
    if (cost >= payoff)
      continue;
    m += (payoff - cost);
  }
  cout << m;
  return (0);
}

```

