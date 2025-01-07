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

# Hint

<details>
<summary> <font size="4"> hint 1 </font> </summary>
<div markdown="1">

knap sack problem

</div>
</details>

# Tricky point

<details>
<summary> <font size="4"> Tricky point 1. why add 0.5f? </font> </summary>
<div markdown="1">

float type to int type can occur abandon error during floor or round.

</div>
</details>

# Trouble shooting

<details>
<summary> <font size="4"> Trouble 1. float point error </font> </summary>
<div markdown="1">

```C++
int main()
{
  for (double i = 0.01; i <= 10.; i += 0.01)
    cout << i << " " << int(i * 100) << '\n';
}
```

expected result :
```
7.53 753
7.54 754
7.55 755
7.56 756
7.57 757
```

result : 
```
7.54 753
7.55 754
7.56 755
7.57 756
```

correct : 
```
int main()
{
    for (double i = 0.01; i <= 10.; i += 0.01)
        cout << i << " " << int(i * 100 + 0.5f) << '\n';
}
```


</div>
</details>

# Code
```cpp []

```

