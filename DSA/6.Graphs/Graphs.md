# Graphs
Graph is a data structure that consists of a finite set of vertices and a set of edges that connect a pair of vertices.


## Graph Representation
* **Adjacency Matrix** - An Adjacency Matrix is a square matrix used to represent a finite graph. The elements of the matrix indicate whether pairs of vertices are adjacent or not in the graph.
  
* **Adjacency List** - An Adjacency List is a collection of unordered lists used to represent a graph. Each list describes the set of neighbors of a vertex in the graph.


## Types of Graphs
* **Directed Graph**  - A Directed Graph is a graph in which the edges have a direction, i.e., the edges point from one vertex to another.
  
* **Undirected Graph** - An Undirected Graph is a graph in which the edges do not have a direction, i.e., the edges connect two vertices without pointing from one to another.
  
* **Weighted Graph** - A Weighted Graph is a graph in which each edge has a weight or cost associated with it.


## Graph Traversal
* **Breadth First Search** - BFS is an algorithm for traversing a graph in a breadth-first manner, i.e., it explores all the vertices at the current depth before moving on to the vertices at the next depth level.
  
* **Depth First Search** - DFS is an algorithm for traversing a graph in a depth-first manner, i.e., it explores as far as possible along each branch before backtracking.


## Graph Algorithms
* **Dijkstra's Algorithm** - Dijkstra's Algorithm is an algorithm for finding the shortest path between two vertices in a weighted graph.
  
* **Prim's Algorithm** - Prim's Algorithm is an algorithm for finding the minimum spanning tree in a weighted graph.
  
* **Kruskal's Algorithm** - Kruskal's Algorithm is an algorithm for finding the minimum spanning tree in a weighted graph.
  
* **Topological Sort** - Topological Sort is an algorithm for ordering the vertices of a directed acyclic graph (DAG) in a linear order such that for every directed edge (u, v), vertex u comes before vertex v in the ordering.

`Note:` **Minimum spanning tree** is a tree that connects all vertices in a graph with the minimum possible total edge weight. In other words, it is a subset of the edges of a connected, weighted, undirected graph that connects all the vertices together, without any cycles, and with the minimum possible total edge weight.

# Prim's Algorithm
Prim's Algorithm is a popular algorithm for finding the minimum spanning tree (MST) in a weighted, undirected graph. The MST is a tree that connects all vertices in a graph with the minimum possible total edge weight.

Here's a high-level overview of how Prim's Algorithm works:

1) Start with an empty minimum spanning tree.

2) Choose any vertex from the graph and add it to the MST.

3) Find the shortest edge connecting the MST to a vertex not yet in the MST. Add that edge and the connected vertex to the MST.

4) Repeat step 3 until all vertices are included in the MST.

The algorithm continues to grow the MST by adding the shortest edge that connects the MST to a vertex not yet in the MST. This ensures that the total weight of the edges in the MST is minimized.

Prim's Algorithm can be implemented using a variety of data structures, such as a priority queue, to efficiently find the shortest edge connecting the MST to a vertex not yet in the MST.

Here's a simple example of how Prim's Algorithm might work on a small graph:

1) Start with an empty MST.
   
2) Choose any vertex, say vertex A, and add it to the MST.

3) Find the shortest edge connecting the MST (which currently only contains vertex A) to a vertex not yet in the MST. Suppose the shortest edge is (A, B) with weight 3. Add edge (A, B) and vertex B to the MST.

4) Find the shortest edge connecting the MST (which now contains vertices A and B) to a vertex not yet in the MST. Suppose the shortest edge is (B, C) with weight 2. Add edge (B, C) and vertex C to the MST.

5) Repeat this process until all vertices are included in the MST.

The final MST would include edges (A, B), (B, C), (C, D), and (D, E), with a total weight of 12.

# Kruskal's Algorithm
Kruskal's algorithm is a popular algorithm for finding the minimum spanning tree (MST) of a connected, weighted graph. The MST is a tree that connects all vertices in the graph with the minimum possible total edge weight.

Kruskal's algorithm works by sorting all the edges in the graph in non-decreasing order of their weights. Then, it iteratively adds the smallest edge that does not form a cycle with the edges already in the MST.

Here are the steps of Kruskal's algorithm:

1) Sort all the edges in the graph in non-decreasing order of their weights.

2) Initialize an empty set to represent the MST.

3) While the MST does not include all vertices in the graph: a. Pick the smallest edge that is not yet in the MST. b. Check if adding the edge to the MST would form a cycle. c. If the edge does not form a cycle, add it to the MST.

The key idea behind Kruskal's algorithm is to add edges to the MST in a way that avoids forming cycles. This is achieved by using a data structure called a disjoint set union (DSU) to keep track of the connected components of the graph.

A DSU is a data structure that supports two operations:

* `MakeSet(x)`: Create a new set containing only the element x.
* `Union(x, y)`: Merge the sets containing the elements x and y.

By using a DSU, Kruskal's algorithm can efficiently check if adding an edge to the MST would form a cycle. If the two endpoints of the edge are in different sets, then adding the edge would not form a cycle, and the sets can be merged.

Here's an example of how Kruskal's algorithm might work on a simple graph:

1) Sort all the edges in the graph in non-decreasing order of their weights:
    * (A, B) with weight 3
    * (B, C) with weight 4
    * (C, D) with weight 5
    * (A, D) with weight 6
    * (B, D) with weight 7

2) Initialize an empty set to represent the MST.

3) While the MST does not include all vertices in the graph:
    * Pick the smallest edge that is not yet in the MST: (A, B) with weight 3.
    
    * Check if adding the edge to the MST would form a cycle: since A and B are not in the same set, adding the edge would not form a cycle.
    
    * Add the edge to the MST and merge the sets containing A and B.
    
    * Pick the smallest edge that is not yet in the MST: (B, C) with weight 4.
    
    * Check if adding the edge to the MST would form a cycle: since B and C are not in the same set, adding the edge would not form a cycle.
    
    * Add the edge to the MST and merge the sets containing B and C.
    
    * Pick the smallest edge that is not yet in the MST: (C, D) with weight 5.
    
    * Check if adding the edge to the MST would form a cycle: since C and D are not in the same set, adding the edge would not form a cycle.
    
    * Add the edge to the MST and merge the sets containing C and D.
    
    * Pick the smallest edge that is not yet in the MST: (A, D) with weight 6.
    
    * Check if adding the edge to the MST would form a cycle: since A and D are in the same set, adding the edge would form a cycle.
    
    * Skip this edge and move on to the next one.
    
    * Pick the smallest edge that is not yet in the MST: (B, D) with weight 7.
    
    * Check if adding the edge to the MST would form a cycle: since B and D are not in the same set, adding the edge would not form a cycle.
    
    * Add the edge to the MST and merge the sets containing B and D.

The final MST would include edges (A, B), (B, C), (C, D), and (B, D), with a total weight of 15.

Kruskal's algorithm is a simple and efficient algorithm for finding the MST of a connected, weighted graph. It has a time complexity of O(E log E) or O(E log V), where E