# Union find
The Union-Find algorithm, also known as the disjoint-set data structure, is a data structure and algorithm used to efficiently manage a collection of disjoint sets. It provides two main operations: union and find.

The "union" operation takes two elements (or sets) and merges them into a single set, while the "find" operation determines which set an element belongs to. The algorithm maintains a set of disjoint sets as a forest, where each node in the forest represents a set, and the parent of each node is another node in the same set.

Initially, each element is considered as a separate set. When a union operation is performed between two elements, the algorithm finds the roots of their respective sets and merges them by making one of the roots the parent of the other root.

The find operation is performed by traversing up the tree from a given element until the root is reached. The root represents the set to which the element belongs. The algorithm also includes a path compression optimization, which flattens the tree by making each node point directly to the root during the find operation. This reduces the time complexity of the find operation to O(log n) in practice.

The Union-Find algorithm is widely used in various graph algorithms such as Kruskal's algorithm for finding the minimum spanning tree of a graph and in clustering algorithms for grouping similar data points together.

The time complexity of the Union-Find algorithm is O(m α(m, n)), where m is the number of operations (union and find) and n is the number of elements in the sets. α is the inverse Ackermann function, which grows very slowly and is practically constant for all practical values of n. Therefore, the Union-Find algorithm is considered to have almost constant time complexity in practice.

In summary, the Union-Find algorithm is a data structure and algorithm used to manage disjoint sets efficiently. It provides two main operations: union and find. The algorithm maintains a forest of trees where each node represents a set, and the roots of the trees represent the distinct sets. The time complexity of the Union-Find algorithm is O(m α(m, n)), where α is the inverse Ackermann function.

# Kruskal Algorithm

# Prims Algorithm

# 1B_min_span
| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| ? | [1197](https://www.acmicpc.net/problem/1197) | [1197.cpp](./1197/1197.cpp) | be caution for merging group |

## merging group counter example (not using union algo)
* counter example : merging v1, v5 groups
```c++
---
v1~v4, v7 = g1 
---
v5~v6, v8~v10 = g2
---
fori 1 ~ 10 if (g[i] == g[v1] || g[i] == g[v5]) -> g[i] = min(g[v1], g[v5])
---
result = v1~v7 = g1, v8~v10 = still g2
```
