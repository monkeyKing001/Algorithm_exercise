# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
Push present[i] check if there is any gift that cannot get simutaneously with present[i].

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
$$ O(nlogn) $$

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
$$ O(n) $$

# Hint

<details>
<summary> <font size="3"> hint 1. </font> </summary>
<div markdown="1">

sort presents by what?

</div>
</details>

<details>
<summary> <font size="3"> hint 2. </font> </summary>
<div markdown="1">

we need bag data structure. and compare the cheapest present's price in the bag and now presents[i]'s price

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
<summary> <font size="3"> Trouble 1. wrong ans. </font> </summary>
<div markdown="1">

Error in updating current value sum and max ans.

Wrong : 
```
while (bag.size() != 0 && (price - bag.front().PRICE) >= d)
 ans -= bag.front().VALUE, bag.pop_front();
bag.push_back(p), ans += value;

```

Correct:
```
while (bag.size() != 0 && (price - bag.front().PRICE) >= d)
 temp -= bag.front().VALUE, bag.pop_front();
bag.push_back(p), ans += value;
ans = max(ans, temp);

```

</div>
</details>

<details>
<summary> <font size="3"> Trouble 2. poping error. </font> </summary>
<div markdown="1">

Error in poping

Wrong : 
```
if (bag.size() != 0 && (price - bag.front().PRICE) >= d)
 ans -= bag.front().VALUE, bag.pop_front();
bag.push_back(p), ans += value;

```

Correct:
```
while (bag.size() != 0 && (price - bag.front().PRICE) >= d)
 temp -= bag.front().VALUE, bag.pop_front();
bag.push_back(p), ans += value;
ans = max(ans, temp);

```

</div>
</details>


# Code
```cpp []

```

