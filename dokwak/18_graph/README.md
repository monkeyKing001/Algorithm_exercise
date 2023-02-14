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


# 18_graph
| level | problem | my_ans | hint |
| :--: | :--: | :--: | :--: |
| easy | [11742](https://www.acmicpc.net/problem/11742) | [11742.cpp](./11742/11742.cpp) | if pop the queue, size will be mutated too. get size var as const not by size() dynamically. |
| easy | [1260](https://www.acmicpc.net/problem/1260) | [1260.cpp](./1260/1260.cpp) |  |
