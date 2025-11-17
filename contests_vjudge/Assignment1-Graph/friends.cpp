// We have some groups, you want to calculate number of people in each group and output max number of people in one group
// Idea: Calculate number of nodes in each component, compare it with max_number: if it is greater: update max_number

#include <iostream>
#include <vector>   
using namespace std;


// DFS
void dfs(int node, vector<vector<int>>& adj_list, vector<bool>& visited ,int& count){
    visited[node] = true;
    count ++;
    for (int neigh : adj_list[node]){
        if (!visited[neigh])
        {
            dfs(neigh, adj_list, visited, count);
        }
        
    }
}

int main() {
    int t;
    cin >> t;
    while (t-- >0)
    {
        int nodes, edges;
        cin >> nodes >> edges;
        vector<vector<int>> adj_list(nodes);
        for (int i = 0; i < edges; i++)
        {
            int from, to;
            cin >> from >> to;
            from--;
            to--;
            adj_list[from].push_back(to);
            adj_list[to].push_back(from);
        }
        int max_group = 0;
        vector<bool> visited(nodes, false);
        for (int i = 0; i < nodes; i++)
        {
            int count = 0;
            if (visited[i] == false)
            {
                dfs(i, adj_list, visited ,count);
                max_group = max(max_group, count); // take the maximum
            }
            
        }
        cout << max_group << endl;
    }
    
    return 0;
}