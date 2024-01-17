### Topologty sort
Topology sort, also known as topological sorting, is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v in the ordering. In other words, topology sort orders the vertices in a DAG from "source" vertices (vertices with no incoming edges) to "sink" vertices (vertices with no outgoing edges).

The idea behind topology sort is that if vertex u comes before vertex v in the ordering, then there cannot be a directed edge from v to u. This property is useful in many applications, such as determining the order in which tasks should be performed in a project or scheduling jobs on a computer.

Algorithmically, topology sort can be performed using a modified depth-first search (DFS) algorithm. The algorithm works as follows:

1. Choose any vertex v in the graph that has no incoming edges.
2. Visit vertex v and mark it as visited.
3. For each neighbor w of v, remove the edge (v, w) from the graph.
4. Recursively perform steps 1-3 on the remaining vertices in the graph.
5. Add vertex v to the beginning of the topologically sorted list.
6. The algorithm repeats until all vertices in the graph have been visited. If the graph contains a cycle, then no topology sort is possible because a cycle implies that there is no way to order the vertices such that every directed edge is satisfied.

Topology sort has a time complexity of O(|V| + |E|), where |V| is the number of vertices in the graph and |E| is the number of edges. This is because the algorithm visits each vertex and each edge exactly once.

In summary, topology sort is a useful algorithm for determining the order in which to perform tasks or schedule jobs in a project. It requires a directed acyclic graph and can be performed using a modified depth-first search algorithm. The time complexity is O(|V| + |E|).

# 1A_top_sort
| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| easy | [2252](https://www.acmicpc.net/problem/2252) | [2252.cpp](./2252/2252.cpp) |  |
| hard | [pro_118668](https://school.programmers.co.kr/learn/courses/30/lessons/118668) | [pro_118668.cpp](./pro_118668/pro_118668.cpp) |  |
| mid | [2623](https://www.acmicpc.net/problem/2623) | [2623.cpp](./2623/2623.cpp) | topology |
| ? | [1005](https://www.acmicpc.net/problem/1005) | [1005.cpp](./1005/1005.cpp) |  |
| mid | [1325](https://www.acmicpc.net/problem/1325) | [1325.cpp](./1325/1325.cpp) | topology travel all the way and add total indegree. how to deal with cycle? |
| hard | [2056](https://www.acmicpc.net/problem/2056) | [2056.cpp](./2056/2056.cpp) | be caution for get start time for work nodes. |
