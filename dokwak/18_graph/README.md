# Graph
## Graph introduction.
A graph is a mathematical data structure that consists of a set of vertices (also called nodes) and a set of edges that connect the vertices. Graphs are widely used to model real-world problems and relationships, and they have many applications in fields such as computer science, engineering, and mathematics.

## vertices and edges
In a graph, vertices represent objects or entities, and edges represent relationships or connections between the objects. For example, in a social network, vertices could represent people, and edges could represent their relationships, such as friendship. In a transportation network, vertices could represent cities, and edges could represent roads or flights connecting the cities.

## directed, undirected graph
There are two main types of graphs: directed graphs and undirected graphs. In a directed graph, edges have a direction, and they connect one vertex to another in a specific direction. In an undirected graph, edges don't have a direction, and they connect two vertices in both directions.

## weighted, unweighted graph
Graphs can also be weighted or unweighted. In a weighted graph, each edge has a weight or cost associated with it, which represents the cost of moving from one vertex to another along that edge. In an unweighted graph, edges don't have a weight.

## cyclic and acyclic graph
Graphs can also be cyclic or acyclic. In a cyclic graph, there exists at least one path that starts and ends at the same vertex. In an acyclic graph, there is no such path.

## applications
There are many algorithms and techniques for working with graphs, including searching for paths, finding shortest paths, detecting cycles, and computing the connected components. Graphs are an important and versatile data structure, and they are widely used in many areas of computer science and other fields.

## expression
Each of these representations has its own advantages and disadvantages, and the choice of representation depends on the specific use case and the requirements of the graph algorithm. In general, adjacency matrices are better for dense graphs, while adjacency lists and edge lists are better for sparse graphs.

### Adjacency Matrix
Adjacency Matrix: An adjacency matrix is a two-dimensional matrix that represents a graph, where each row and column represents a vertex, and the entries in the matrix represent the edges between vertices. If there is an edge between vertices i and j, then the entry in row i and column j is set to 1, and 0 otherwise. For weighted graphs, the matrix entries can be set to the edge weight instead of 1.
> space complextity 
- O(v^2)

>  time complextity 
-  Finding if there is an edge between two vertices: O(1)
- Finding all the neighbors of a vertex: O(V)
- Adding a new edge: O(1)
- Removing an edge: O(1)
- Traversing all the vertices: O(V^2)

### Adjacency List
Adjacency List: An adjacency list is a collection of lists, where each list represents a vertex, and its elements represent the vertices that are adjacent to it. For example, if there is an edge from vertex i to vertex j, then j would be included in the list for vertex i. This representation is more efficient for sparse graphs, where the number of edges is much smaller than the number of vertices.
> space complextity
- O(E + V);

> time complextity
- Finding if there is an edge between two vertices: O(degree(v)) where degree(v) is the degree of the vertex v.
- Finding all the neighbors of a vertex: O(degree(v))
- Adding a new edge: O(1)
- Removing an edge: O(degree(v))
- Traversing all the vertices: O(V + E)


### Edge list
Edge List: An edge list is a simple list of edges, where each edge is represented as a pair of vertices. For example, an edge from vertex i to vertex j would be represented as the pair (i, j). This representation is simple and easy to understand, but it may not be as efficient for some graph algorithms as the other two representations.
> space complextity
- O(E)

> time complextity

- Finding if there is an edge between two vertices: O(E)
- Finding all the neighbors of a vertex: O(E)
- Adding a new edge: O(1)
- Removing an edge: O(E)
- Traversing all the vertices: O(E)

# Dijkstra Algorithm
## Implementation Rule
### 1. need 3 data structure
- PriorityQueue
- adjacent list(graph)
- cost_to_visit array
- if don't need updating, do not push in queue


# 18_graph
| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| easy | [11742](https://www.acmicpc.net/problem/11742) | [11742.cpp](./11742/11742.cpp) | if pop the queue, size will be mutated too. get size var as const not by size() dynamically. |
| easy | [1260](https://www.acmicpc.net/problem/1260) | [1260.cpp](./1260/1260.cpp) |  |
| hard | [pro_132266](https://school.programmers.co.kr/learn/courses/30/lessons/132266) | [pro_132266.cpp](./pro_132266/pro_132266.cpp) | bfs, given_path, min_cost |
| easy | [2606](https://www.acmicpc.net/problem/2606) | [2606.cpp](./2606/2606.cpp) |  |
| hard | [1753](https://www.acmicpc.net/problem/1753) | [1753.cpp](./1753/1753.cpp) | Floyd Algorithm and 2d array is memory limit exceed. use Dijkstra. becare for the multiple edge |
| ? | [1504](https://www.acmicpc.net/problem/1504) | [1504.cpp](./1504/1504.cpp) |  |
| hard | [1967](https://www.acmicpc.net/problem/1967) | [1967.cpp](./1967/1967.cpp) | no floyd, bfs(Queue) or Dijkstra(PQ). do not use -1 |
| ? | [1167](https://www.acmicpc.net/problem/1167) | [1167.cpp](./1167/1167.cpp) |  |
| ? | [2263](https://www.acmicpc.net/problem/2263) | [2263.cpp](./2263/2263.cpp) |  |
| easy | [20040](https://www.acmicpc.net/problem/20040) | [20040.cpp](./20040/20040.cpp) | union find |
| hard | [1238](https://www.acmicpc.net/problem/1238) | [1238.cpp](./1238/1238.cpp) | Floyd -> TLEDijkstra |
| hard | [9466](https://www.acmicpc.net/problem/9466) | [9466.cpp](./9466/9466.cpp) | how to cycle check and duplicated travel check? visited & finished. before rec, after rec |
| ? | [samsung_sw_01](https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AYkfqUaKLp0DFASe&categoryId=AYkf6zw6MwMDFASe&categoryType=BATTLE&battleMainPageIndex=) | [samsung_sw_01.cpp](./samsung_sw_01/samsung_sw_01.cpp) | cycle doesnt work. why? edge_index wrong coding |
