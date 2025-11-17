// Check if undirected graph is cyclic or acyclic

/*
    ================================
        GUIDE: Check Cyclic (Directed Graph)
    ================================

    Goal:
    ---------
    Detect whether the given directed graph contains a cycle.

    Core Idea:
    -----------
    - A cycle exists if, during DFS traversal, we visit a node that is 
      already in the current recursion path (recStack).
    - 'visited' keeps track of all nodes that have been fully explored.
    - 'recStack' tracks the nodes in the current DFS recursion chain.

    Approach:
    ----------
    1. Initialize two lists (or arrays):
        - visited[node] = true → if node has been completely processed.
        - recStack[node] = true → if node is currently in the DFS path.

    2. For each node in the graph:
        - If it hasn’t been visited, call DFS_Util(node).
        - Inside DFS_Util:
            a. Mark current node as visited and add it to recStack.
            b. Explore all adjacent nodes:
                - If an adjacent node is not visited → recursively DFS it.
                - If an adjacent node is already in recStack → cycle detected.
            c. Remove current node from recStack after exploration.

    3. If any DFS call detects a cycle → return true.
       Otherwise → return false.

    Example:
    ---------
        A → B → C → A  ⇒ cyclic
        A → B → C      ⇒ acyclic
*/
