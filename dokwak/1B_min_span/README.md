# Union find
The Union-Find algorithm, also known as the disjoint-set data structure, is a data structure and algorithm used to efficiently manage a collection of disjoint sets. It provides two main operations: union and find.

The "union" operation takes two elements (or sets) and merges them into a single set, while the "find" operation determines which set an element belongs to. The algorithm maintains a set of disjoint sets as a forest, where each node in the forest represents a set, and the parent of each node is another node in the same set.

Initially, each element is considered as a separate set. When a union operation is performed between two elements, the algorithm finds the roots of their respective sets and merges them by making one of the roots the parent of the other root.

The find operation is performed by traversing up the tree from a given element until the root is reached. The root represents the set to which the element belongs. The algorithm also includes a path compression optimization, which flattens the tree by making each node point directly to the root during the find operation. This reduces the time complexity of the find operation to O(log n) in practice.

The Union-Find algorithm is widely used in various graph algorithms such as Kruskal's algorithm for finding the minimum spanning tree of a graph and in clustering algorithms for grouping similar data points together.

The time complexity of the Union-Find algorithm is O(m α(m, n)), where m is the number of operations (union and find) and n is the number of elements in the sets. α is the inverse Ackermann function, which grows very slowly and is practically constant for all practical values of n. Therefore, the Union-Find algorithm is considered to have almost constant time complexity in practice.

In summary, the Union-Find algorithm is a data structure and algorithm used to manage disjoint sets efficiently. It provides two main operations: union and find. The algorithm maintains a forest of trees where each node represents a set, and the roots of the trees represent the distinct sets. The time complexity of the Union-Find algorithm is O(m α(m, n)), where α is the inverse Ackermann function.

# Kruskal Algorithm
Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, weighted graph. The MST is a subgraph that includes all vertices of the original graph and has the minimum possible total edge weight. The algorithm was named after its inventor Joseph Kruskal.

Kruskal's algorithm works by initially sorting all the edges of the graph in increasing order of weight. It then starts with the edge with the smallest weight and adds it to the MST if it does not create a cycle. If the edge creates a cycle, it is discarded, and the next smallest edge is considered. This process continues until all vertices are in the MST.

The algorithm uses a disjoint-set data structure to keep track of the connected components of the graph and to determine whether adding an edge to the MST creates a cycle. Initially, each vertex is a separate set, and when an edge is added to the MST, the disjoint sets of the two vertices connected by the edge are merged.

Kruskal's algorithm has a time complexity of O(E log E), where E is the number of edges in the graph. This is because the algorithm sorts the edges in O(E log E) time and performs at most E find and union operations on the disjoint sets.

Kruskal's algorithm is widely used in various applications such as network design, image segmentation, and clustering. It is one of the simplest and most efficient algorithms for finding the MST of a graph.

In summary, Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree of a weighted, connected graph. It works by sorting the edges in increasing order of weight, adding the smallest edge that does not create a cycle to the MST, and repeating until all vertices are in the MST. The algorithm uses a disjoint-set data structure to keep track of the connected components of the graph and has a time complexity of O(E log E).

# Prims Algorithm
Prim's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a weighted, connected graph. The MST is a subgraph that includes all vertices of the original graph and has the minimum possible total edge weight. The algorithm was named after its inventor Robert Prim.

Prim's algorithm works by starting with an arbitrary vertex and adding the minimum-weight edge that connects it to an unvisited vertex. It then adds the vertex to the MST and repeats the process until all vertices are in the MST. At each step, the algorithm chooses the minimum-weight edge that connects a vertex in the MST to an unvisited vertex.

The algorithm uses a priority queue to keep track of the minimum-weight edges that connect vertices in the MST to unvisited vertices. Initially, all vertices are unvisited, and their weights are set to infinity. As the algorithm progresses, the weights of the edges are updated, and the priority queue is updated accordingly.

Prim's algorithm has a time complexity of O(E log V), where E is the number of edges in the graph and V is the number of vertices. This is because the algorithm performs at most E iterations, and each iteration takes O(log V) time to update the priority queue.

Prim's algorithm is widely used in various applications such as network design, image segmentation, and clustering. It is one of the simplest and most efficient algorithms for finding the MST of a graph.

In summary, Prim's algorithm is a greedy algorithm used to find the minimum spanning tree of a weighted, connected graph. It works by starting with an arbitrary vertex, adding the minimum-weight edge that connects it to an unvisited vertex, and repeating until all vertices are in the MST. The algorithm uses a priority queue to keep track of the minimum-weight edges and has a time complexity of O(E log V).

## merging group counter example (Kruskal not using union algo)
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

# 1B_min_span
| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| mid | [1197](https://www.acmicpc.net/problem/1197) | [1197.cpp](./1197/1197.cpp) | be caution for merging group |
| hard | [1368](https://www.acmicpc.net/problem/1368) | [1368.cpp](./1368/1368.cpp) | need to be familiar with Kruskal, Prim, welling smallest, welling also in pq |
