/*
    ================================
          GUIDE: Topological Sort
    ================================

    Meaning:
    -----------
    - Topological Sort means arranging the nodes of a Directed Acyclic Graph (DAG)
      in an order that represents how tasks (or processes) can be executed.
      In this order, every node appears **before** all nodes that depend on it.

      → Example idea:
         If you must complete task A before task B, then in the topological order,
         A will appear before B.

    Goal:
    ---------
    - To find a linear ordering of all vertices in a Directed Acyclic Graph (DAG)
      such that for every directed edge (u → v), vertex 'u' appears before 'v' 
      in the ordering.

    Important:
    ------------
    - Works **only for Directed Acyclic Graphs (DAGs)**.
    - If the graph contains a cycle, Topological Sort is not possible.

    Core Idea:
    -----------
    - Perform a DFS traversal.
    - Once a node finishes (all its children are processed), 
      push it onto a stack.
    - After DFS finishes for all nodes, 
      the stack (reversed order) gives the topological ordering.

    Approach (DFS-based):
    ----------------------
    1. Initialize a visited[] array to track visited nodes.
    2. For each unvisited node:
        a. Call DFS(node).
        b. In DFS:
            - Mark node as visited.
            - Recursively visit all unvisited neighbors.
            - After finishing all neighbors, push node onto a stack.
    3. After DFS completes for all nodes:
        - Pop elements from the stack to get the Topological Order.

    Example:
    ---------
        Graph:
            5 → 0 ← 4
            ↓    ↑
            2 → 3 → 1

        One valid Topological Order:
            4 5 2 3 1 0

    Note:
    -----
    - Topological Sort is widely used in:
        * Task scheduling
        * Course prerequisite planning
        * Build dependency resolution
*/
