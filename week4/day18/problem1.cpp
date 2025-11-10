// calculate number of connected components in disconnected graph

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int>> adj_list){
    visited[node] = true;
    cout << "Visit node " << node << endl;
    for (int neigh : adj_list[node]){
        if (visited[neigh] == false){
            dfs(neigh, visited, adj_list);
        }
    }

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
    int count = 0; // for counting number of connected components
    vector<bool> visited(nodes, false);

    for (int i =0; i< nodes; i++){
        if (visited[i] == false){
            dfs(i, visited, adj_list);
            count ++;
        }
       
    }
    cout << "number of connnected componenst is " << count << endl;
    return 0;
}