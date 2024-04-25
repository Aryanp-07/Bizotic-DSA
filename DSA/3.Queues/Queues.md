# Queues
Queues are open on both ends. It follows FIFO principle. Queues have 2 operations - 
* Enqueue (Adding an element)
* Dequeue (Removing an element)
  
Queues require two pointers - `Front` and `Back`

# Priority Queues
Priority Queues are a variation of Queues. The elements with higher priority are pushed closer to the front and dequeued first. 
Priority Queues are implemented using-
* Arrays
* Linked List
* Binary Search Tree / Binary Tree
* Heap

Priority queues are used in algorithms to improve their efficiency, such as Dijkstra's algorithm for finding the shortest path in a graph and the different search algorithm for path finding.

## Properties of Priority Queues
* Every item has a priority associated with it.
* An element with high priority is dequeued before an element with low priority.
* If two elements have the same priority, they are served according to their order in the queue.

## Types of Priority Queues
* Ascending order Priority Queue
* Descending order Priority Queue