# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
1. postfix expression?
-> too tricky

2. stack implementation
-> Intuitive

# Approach
<!-- Describe your approach to solving the problem. -->
()
2
(())
4
()()
4
()[]
5
(()[])

1 1 2 * 1 3 * 2 *
-> 1 2 * 1 3 * + 2 *            ()
-> 1 3 * + 2 *                  (2) 
-> + 2 *                        (2 3)
-> 2 *                          (5)


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
<summary> <font size="3"> Tricky point 1. post expression </font> </summary>
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

```

