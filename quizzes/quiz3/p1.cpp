// First problem in monday quiz: check it a graph is a tree

// A tree is a graph who is connected, Acyclic, and has (n-1) edges where n is count of nodes 
// You need only to prove that it is connected and has n-1 edges (that gurantee it is acyclic)

#include <iostream>
#include <vector>
using namespace std;


// node, visiited, adj_list, no_of_visited_nodes
void dfs(int node, vector<bool>& visited, 
                     vector<vector<int>>& adj_list, int& no_of_visited_nodes)
    {
    visited[node] = true;
    no_of_visited_nodes ++; 
    for (int neigh : adj_list[node]){
        if (visited[neigh] == false){
            dfs(neigh, visited, adj_list, no_of_visited_nodes);
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    if (edges == (nodes-1)){
        vector<vector<int>> adj_list(nodes);
        for (int i = 0; i< edges ; i++){
            int from, to;
            cin >> from >> to;
            from--;
            to--;
            adj_list[from].push_back(to);
            adj_list[to].push_back(from); // as undirected in that problem
        }

        // Check if it is connected: (if dfs visited all nodes: connected)
        vector<bool> visited(nodes, false);
        int no_of_visited_nodes=0;
        dfs(0, visited, adj_list, no_of_visited_nodes);

        if(no_of_visited_nodes == nodes) cout << "YES";
        else cout << "NO";

    }
    else{
        cout << "NO";
    }
    
    return 0;
}