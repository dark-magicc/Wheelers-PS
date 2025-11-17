// Check if undirected graph is cyclic or acyclic
#include <iostream>
#include <vector>
using namespace std;

// Purpose: This function performs a DFS traversal to detect cycles in an undirected graph.
// Returns true if a cycle exists, otherwise false.
// 
// Concept:
// - During traversal, if we encounter a node that has already been visited and it is not the parent of the current node,
//   this indicates the presence of a cycle.
// - To differentiate between revisiting a parent (which is valid backtracking) and visiting another previously visited node,
//   we pass a 'parent' parameter to the function.
// - 'Backtracking' means returning to the immediate previous node (the parent) during DFS, which should not be considered a cycle.
bool modified_dfs(int node, int parent ,vector<bool>& visited, vector<vector<int>> adj_list){
    visited[node] = true;
    cout << "Visit node " << node << endl;
    for (int neigh : adj_list[node]){
        if (visited[neigh] == false){
            if(modified_dfs(neigh, node ,visited, adj_list) == true){  // call the same fun and check if cyclic
                return true;   // indicate cyclic
            }
        }
        else if (neigh != parent){

            return true; // indicate cyclic
        }

    }
    return false;   // If I loop over the nodes and didn't find any cycle, so return false
}



// This function iterates through all connected components of the graph.
// For each unvisited node, it calls DFS_Modified to check whether that component contains a cycle.
// If any component is found to be cyclic, the function prints "Cyclic" and returns immediately.
void is_cyclic(vector<vector<int>> adj_list, int nodes){ 
    vector<bool> visited(nodes, false);

    for (int i =0; i< nodes; i++){  // check if graph disconnecd
        if (visited[i] == false){
            // check if graph cyclic -> true
            if(modified_dfs(i, -1 ,visited, adj_list) == true){
                cout << "cyclic";
                return;
            }
        }
    }
    cout <<"Acyclic";
    return;       

}

int main() {
    int nodes = 7;
    vector<vector<int>> adj_list (nodes);
    
    adj_list = {
        {1,2}, //0
        {0,2,3}, //1
        {0,1,3}, //2
        {1,2}, //3
        {5,6}, //4
        {4}, //5
        {4} //6
    };
    // call the function
    is_cyclic(adj_list, nodes);   
    return 0;
}