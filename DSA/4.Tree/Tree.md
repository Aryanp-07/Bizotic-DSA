# Tree
Trees are a type of data structure that consists of nodes in a parent/child relationship. Each node can have zero or more children. The node consists of data, left and right pointers. 

## Operations
* Insertion
* Deletion
* Traversal (In-order, Pre-order, Post-order, Level-order)
* Searching (BFS, DFS)

## Types of Trees
* Binary Tree
* Binary Search Tree
* AVL Tree
* Red-Black Tree
* Heap
* Trie
* B-Tree
* B+ Tree
* B* Tree

# Binary Tree
Binary trees are a type of tree where each node has at most two children. 

## Types of binary trees
* **Full Binary Tree**

    Every node has either 0 or 2 children.

* **Complete Binary Tree**

     Every level is completely filled except the last level and the last level has all nodes as left as possible.

* **Perfect Binary Tree**

    It is a complete binary tree in which all the internal nodes have two children and all leaf nodes are at the same level.

* **Balanced Binary Tree**

    The difference between the height of the left subtree and the right subtree is not more than 1.

* **Degenerate Binary Tree**

    The left and right subtrees of every node have the same height.

* **Skewed Binary Tree**

    The left or right subtree is empty and the other subtree is non-empty.

## Searching Algorithms
* Breadth First Search

    * In BFS, we start at the tree root and explore each neighbor before going to the next level of the tree.
    
    * BFS is often used to find the shortest path between two nodes in a graph.
    
    * Traversal Order-
        * Level Order
        * Reverse Level Order

* Depth First Search

    * In DFS, we start at the tree root and explore each neighbor before going to a deeper level of the tree.
  
    * DFS is often used to sort a graph.
  
    * Traversal Order-
        * Pre-order: Root -> Left -> Right
        * Post-order: Left -> Right -> Root
        * In-order: Left -> Root -> Right


# Binary Search Tree
BSTs are a type of binary tree where the left child of a node is less than the node and the right child is greater than the node.
