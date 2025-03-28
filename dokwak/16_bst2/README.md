# 16_bst2

## Binary search trees
### Rules.
1. seperating : l_group -> start ~ mid - 1, r_group -> mid + 1 ~ end
2. exiting : when start > end
3. memoization : in succeeding case, take the sol down on memo.

## C++
### get max element in array
```c++
int max = *max_element(arr, arr + size)
```
`max_element()` returns pointer.
### `max(T1, T2)`
```c++
int max_elm = max(0, (long long)temp); // x compile error
long long max_elm = max((long long)0, (long long)temp); // o compile error
```
t1, t2 must be same type;

## JAVA
### get max element in array
```java
long max_h = Arrays.stream(trees).max().getAsInt();
```

| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| easy | [7662](https://www.acmicpc.net/problem/7662) | [7662.cpp](./7662/7662.cpp) | practice to use a set(multiset) and its iterator |
| mid | [1202](https://www.acmicpc.net/problem/1202) | [1202.cpp](./1202/1202.cpp) | use stl map, set for optimization. |
| mid | [1654](https://www.acmicpc.net/problem/1654) | [1654.cpp](./1654/1654.cpp) | be caution for max_len |
| easy | [2805](https://www.acmicpc.net/problem/2805) | [2805.cpp](./2805/2805.cpp) | cutting under 0 is impossiple |
| hard | [16434](https://www.acmicpc.net/problem/16434) | [16434.cpp](./16434/16434.cpp) | binary search without while loop. ceil with long type is incorrect. casting type to double before ceil is needed |
| ? | [2467](https://www.acmicpc.net/problem/2467) | [2467.cpp](./2467/2467.cpp) |  |
| mid | [1253](https://www.acmicpc.net/problem/1253) | [1253.cpp](./1253/1253.cpp) | two Pointer or bst. if l == i l++, r == i r++ |
| mid | [2110](https://www.acmicpc.net/problem/2110) | [2110.cpp](./2110/2110.cpp) | binary search tree, minimum distance. |
| mid | [2696](https://www.acmicpc.net/problem/2696) | [2696.cpp](./2696/2696.cpp) | not binary search. use pq for bigger, smaller. |
| easy | [11568](https://www.acmicpc.net/problem/11568) | [11568.cpp](./11568/11568.cpp) | Longest Increasing Sequence. |
| easy | [2343](https://www.acmicpc.net/problem/2343) | [2343.cpp](./2343/2343.cpp) |  |
| ? | [1939](https://www.acmicpc.net/problem/1939) | [1939.cpp](./1939/1939.cpp) |  |
| ? | [3020](https://www.acmicpc.net/problem/3020) | [3020.cpp](./3020/3020.cpp) |  |
| ? | [2512](https://www.acmicpc.net/problem/2512) | [2512.cpp](./2512/2512.cpp) |  |
| ? | [2428](https://www.acmicpc.net/problem/2428) | [2428.cpp](./2428/2428.cpp) |  |
| ? | [17266](https://www.acmicpc.net/problem/17266) | [17266.cpp](./17266/17266.cpp) |  |
| hard | [1300](https://www.acmicpc.net/problem/1300) | [1300.cpp](./1300/1300.cpp) | bst. |
| ? | [25343](https://www.acmicpc.net/problem/25343) | [25343.cpp](./25343/25343.cpp) |  |
| mid | [1477](https://www.acmicpc.net/problem/1477) | [1477.cpp](./1477/1477.cpp) | minimum interval |
| ? | [10775](https://www.acmicpc.net/problem/10775) | [10775.cpp](./10775/10775.cpp) |  |
