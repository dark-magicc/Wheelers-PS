// topological sort

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& adj_list, vector<bool>& visited, stack<int>& st){
    visited[node] = true;

    for (int neigh : adj_list[node]){
        if (visited[neigh] == false){
            dfs(neigh, adj_list, visited, st);
        }
    }
    st.push(node);

}

void topo_sort(int nodes, vector<vector<int>>& adj_list){
    stack<int> st;
    vector<bool> visited(nodes, false);
    for (int i = 0; i < nodes; i++){
        if (visited[i] == false){
            dfs(i,adj_list, visited, st);
        }
    }
    while (!st.empty())
    {
        cout << (st.top() +1) << " ";
        st.pop();
    }
    
}

int main() {
    int nodes, edges;
    cin >> nodes>> edges;

    vector<vector<int>> adj_list(nodes);
    for (int i = 0; i< edges; i++){
        int from, to;
        cin>> from >> to;
        from--;to--;
        adj_list[from].push_back(to); // directed graph
    }
    
    topo_sort(nodes, adj_list);
    
    return 0;
}