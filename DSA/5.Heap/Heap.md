# Heaps

A Heap is a special type of tree-based data structure which is a complete binary tree and satisfies the heap property: the value of each note is greater than or equal to the value of its children. This property makes sure that the root node contains the maximum or minimum value(depending on the type of heap), and the values decrease or increase as we move down the tree.

## Types of Heaps

**Max Heap**: In a Max Heap, the key at `root of any subtree is maximum` among all the keys present in its children and their children's children. The same property must be recursively true for all the subtrees in Max-Heap.

**Min Heap**: In a Min Heap, the key at `root of any subtree is minimum` among all the keys present in its children and their children's children. The same property must be recursively true for all the subtrees in Min-Heap.

## Heap Operations

**Insertion**: Inserting a new element to the heap.    

**Deletion**: Deleting an element from the heap.    

**Building a Heap**: Building a heap from a given array.  

**Heapify**: Converting a binary tree into a heap data structure.

## Heap Implementation

Heaps can be implemented using arrays or trees. The root is stored at the first index of the array, and the left and right child of a node at index i are stored at indices 2i and 2i+1 respectively.

## Heap Applications

**Heap Sort**: Using the heap data structure, we can sort an array in O(n log n) time complexity.

**Priority Queue**: A priority queue is an abstract data type which is used to prioritize elements based on their priority. Heaps are used to implement priority queues.

**Graph Algorithms**: Heaps are used in various graph algorithms like Dijkstra's algorithm, Prim's algorithm, etc.

## Time Complexity

| Operation  | Time Complexity |
| :--------- | :-------------- |
| Insertion  | O(log n)        |
| Deletion   | O(log n)        |
| Build Heap | O(n)            |
| Heapify    | O(log n)        |